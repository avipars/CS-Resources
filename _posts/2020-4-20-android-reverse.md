---
title: 'Protecting your Android App against Reverse Engineering and Tampering'
layout: post

external: true
blog: Medium
blog_link: https://medium.com/p/a727768b2e9e

categories: post
tags:
- CS
- Android
- Hacking
- ReverseEngineering
---

Edit: updated in July 2022 with more options and information

I built a premium (paid) android app that has been cracked and modded. Therefore, I started researching ways to secure my code and make it more difficult to modify my app.

Before I continue, You cannot mitigate these issues or completely prevent people from breaking your app. All you can do is make it slightly more difficult to get in and understand your code.

I wrote this article because I felt that the only sources of information just said that it was nearly impossible to protect your app, just don’t leave secrets on the client device. That is partly true, but I wanted to compile sources that can actually assist independent developers like me. Lastly, when you search “android reverse engineer”, all the results are for cracking other peoples apps. There are almost no sources on how to protect your own apps.

So here are some useful blogs and libraries which has helped me make my code more tamper-resistant. Several sources that are less popular have been mentioned in the list below to help you!

This article is geared towards new android developers or ones who haven’t really dealt with reverse engineering and mods before.

Proguard:

This is built into android studio and serves several purposes. The first one is code obfuscation, basically turning your code into gibberish to make it difficult to understand. This can easily be beaten, but it is super simple to add to your app so I still recommend implementing it.

The second function is code shrinking, which is still relevant to this article. Basically, it removes unused resources and code. I wouldn’t rely on this, but it is included by default and worth implementing. The only way of actually checking if it changed anything is by reverse engineering your own APK.

Dexguard:

A tool that isn’t free, but made by the same team of Proguard. I haven’t used it myself, so can’t recommend it.

It includes everything that Proguard has and adds more features. Some notable additions are String and Resource Encryption.

Android NDK:

Writing parts of your app in native code (C or C++) will certainly deter people from reverse engineering your app. There are several downsides to using the NDK, such as performance issues when making JNI calls and you can introduce potential bugs down the line that will be harder to track. You’ll also have to do the garbage collection yourself, which isn’t trivial for beginners.

Warning about DataStore/Shared Preferences:

Do not store critical information to your app in the DataStore (Jetpack) or SharedPreferences. These are great for saving user settings (such as the app theme (dark mode, light mode) or some basic user preference) sin your app, but unfortunately it isn’t really secure.

It is easy to wipe out the information in addition to modify it from the user perspective. An alternative is to use the Android KeyStore

APK Signature comparison:

Essentially, your signing certificate is unique and tied to the production version of your app… so a simple check could be to compare the signature of the end-users APK to your signing certificate signature.

Client-side issues:

This used to be a valid option, but modders might be able to change the cert check when they decompile your app. So if you are still shipping APKS and want to check, please do this on the server side… have the client send a post request with the token and then compare it to one that sits on your (more) secure server.

The move to AABS:

In addition, many people have moved to using AABs which have moved your signing certificate to google’s cloud… So essentially google’ signs your app and therefore the certification code on your end won’t be the same as your end-users.

PiracyChecker:

A popular library on github with some basic ways to mitigate reverse engineering. I included this in one of my apps, but it already has been cracked. There are multiple checks you can run, including an implementation of the Google Play Licensing Check (LVL). The library has been converted to Kotlin for the most part.

This is open source, so you can look at his code and contribute too! Unfortunately, it also means that it is easier to see what is going on under the hood.

The APK signing feature should work but use with caution due to the reasons I mentioned above

javiersantos/PiracyChecker
Android Library An Android library that prevents your app from being pirated / cracked using Google Play Licensing…
github.com

Google’s SafetyNet Attestation API:

This is an amazing option, though I haven’t tested it thoroughly. Basically, you call Google’s Attestation API and they can tell you if the device the app is running on is secure or not. Basically if it is rooted, or using LuckyPatcher for instance. Older versions of Magisk were able to fool Google’s API, since then I think SafetyNet has improved. Newer devices have a hardware level check which tends to be much better!

Server vs client-side checks:

Save whatever you can on the server side, we cannot assume that the client phone or app is secure. This also follows for In App Purchases, while you can do a lot of processing on the client… it is not a good idea for several reasons.

The user could be using an older (and/or modded) version of your app. Any update you push to the client application via the play store (for instance) will not impact this user’s version. Essentially if you add some new checks on the client in a newer version… it won’t do you any good.

You don’t control the client application, but you do control the server…

Pin your certificates!

Even if you have a server side check, reverse engineers can perform a man-in-the-middle attack to modify the outgoing and incoming web traffic. Make sure that your website has an SSL Cert and uses HTTPS. Next, on the client application, you can ensure the client app will communicate with your server securely… via certificate pinning. This certainly makes it more difficult to jump over that hurdle, but it’s still possible. (in laymen’s terms, a noob won’t be able to break in but an expert can).

As I mentioned elsewhere, and many people have said “it’s a game of cat and mouse”. It is impossible or nearly impossible to keep the hackers and script kiddies at bay. But, if you execute the best practices and mitigations it will make their lives that much more difficult and your job a bit easier!

Reverse Engineering Tools

Deguard:

This was a website that I stumbled upon. You upload an APK file, then it uses some algorithms to reverse what proguard does. Now, you can open classes, sometimes with full class names too! I used this to pull some modded versions of my app and see what has been changed more or less. There are manual processes to achieve similar results, but this is faster and requires less work.

http://apk-deguard.com/

Android Anti-Reversing Defenses:

This blog post explains some great defenses to put up against hackers/reverse engineering. I suggest reading it and implementing at least one or two of the methods used. There are code snippets too!

Android Anti-Reversing Defenses
Detection code also often looks for binaries that are usually installed once a device has been rooted. These searches…
mobile-security.gitbook.io

Android Security: Adding Tampering Detection to Your App:

Another great article, also with code snippets about how to protect your app. this piece also includes great explanations about how each method woks.

https://www.airpair.com/android/posts/adding-tampering-detection-to-your-android-app

MobSF:

I heard about this from an Android Reverse Engineering Talk I wa swatching on YouTube. They mentioned this amazing tool in passing. I have never heard of it before but decided to go ahead and test it out. It works on Windows, Linux, and Mac. In short, you run this locally -> upload an APK (no AABs yet), and it analyses it for vulnerbilities. It performs basical checks and shows you a lot of information about an APK, like who signed the cert , app permissions, all the strings, and much more!

I had some issues installing it, but the docs are good and they have a slack channel which came in handy.

https://github.com/MobSF/Mobile-Security-Framework-MobSF

Overall, there are several ways to make your app more difficult to crack. I’d recommend that your app should call an API rather than do the checks locally. It is much easier to modify code on the client rather than on the server.

Let me know if I missed anything, and if you have more ideas!