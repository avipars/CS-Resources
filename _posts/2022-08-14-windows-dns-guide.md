---
title: "How to change your DNS Server in Israel to Cloudflare and Google's and more tips and tricks!"
layout: post
external: true
blog: Everything Tech Review
blog_link: https://tech.aviparshan.com/2022/08/how-to-change-your-dns-server-in-israel.html
categories: post
tags:
- DNS
- Windows
- CMD
---


Here is a guide for how to check your DNS settings and configurations for sites you own or want to visit. Some of these tips are for beginners but there are plenty of new things even for advanced users to learn! 

The terminal/command prompt commands I will be using in the post are only relevant to windows users... If you have a Mac or Linux they will not work... 

1) How to open command prompt and some cool commands
Win + R -> type CMD -> click Ok or press Enter 

Command choices: 

ipconfig - generic stats about your network adapters and IP addresses

ipconfig /all - more detailed view

getmac - returns the MAC address of all the devices on your computer 

2) Run WHOIS locally

whois - want to see who owns a website, when it expires and who the domain registrar is? On windows, this doesn't come built into the operation system but it is a package which you can add do do the check. You can add the path location to your environment variables which allows you to run it in any directory via CMD. 

setx whois "C:\enter your directory here"

in my case:


setx whois "C:\Program Files\whois"

where whois is the folder containing the EXE


Now you can close all your command prompt windows... then re-open one and type: 
whois -v example.com to see all the info on that website (another optional flag is -nobanner to remove some more annoying text)

Alternatively, you can perform a search for whois in your favorite search engine and there are 3rd party websites which provide a similar service. I prefer using the windows package as it's faster and there are no ads or bloatware unlike on those websites. 

3) Get a new IP address 

Exercise Caution with these ones: 

ipconfig /release - releases your DHCP leased IP address... you will lose internet after running this

ipconfig /renew - gets you a new IP address (run this immediately after the release command finishes)

4) Find an IP address from a domain name:
Open CMD and write: ping example.com 

That command also shows you server response time and packet loss...This is a great tool to check and verify if you can access a website or not. 

Command Flags: The syntax is usually as follows "command argument -flag1 -flag2"

Flags are optional additions to the command argument which enable different modes, you can use then in succession just make sure to include a space between them. If you are unsure which flag does what, you can type "command /?", .. then it will fill the screen with all types of flags and what they do!

If you want to check continuously, you can add a -t and it will go on forever... till you hit Ctrl + C or click the X button. 

There are other flags such as -a which is supposed to give you the address of the server, you can also force it to give you an IPV4 address with -4 or -6 to force a IPV6 address

5) Purge DNS Cache Globally
Another powerful tool is purge cache, this let's you submit a request to these DNS services to tell them to refresh their database for the specific domain that you want. 
If it isn't purged, the record should usually update within 72 hours but usually occurs much faster. Essentially, one DNS server finds out the new IP address, then it gets passed on to other level servers, etc. till it is all updated. By "purging" the cache yourself, it can speed up certain parts of the process for customers who are using either Cloudflare (1.1.1.1 or 1.0.0.1) as a DNS provider or Google (8.8.8.8 or 8.8.4.4)

https://1.1.1.1/purge-cache/ (For Cloudflare)
https://developers.google.com/speed/public-dns/cache (For Google)
https://dns.google/cache (also for google)

You want to select the CNAME record (this is what ties the domain to a server via another name), and the A record (ties the name to an IP address). This is meant for domain admins usually when they change a DNS entry to switch servers to notify and have the new IP address ready. 

6) Flush your local DNS cache (on your computer)
ipconfig /flushdns this command flushes/erases the cache of DNS entries that you had... this comes in handy if a website that you want to access changed IP addresses and was unreachable. 
Now, when you make a request with your browser, it will pull the results from scratch. 


7) Nameserver lookup (DNS search)
nslookup example.com (Name Server Lookup)

This is a good way to check if your DNS record is working and if a website exists or not. 
