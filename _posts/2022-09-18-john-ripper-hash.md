---
title: "Cracking linux user passwords with john the ripper"
layout: post
deescription: "For an assignment in our data security course, we had to make users and crack their passwords. I took it one step further by adding a custom rule and the RockYou database"
image: /static/post-image/dalle_script.png
categories: post
tags:
- JohnTheRipper
- Security
- Passwords
- Hashing
---

For starters... we are using john the ripper to crack passcodes, here is my modified config file which can be downloaded with wget on Linux (WSL too)!

The rules are kept in /etc/john/john.conf. First copy it over to the local directory with cp /etc/john/john.conf .
Edit and copy back using sudo cp ./john.conf /etc/john/john.conf

wget https://cs.aviparshan.com//static/security-notes/jonh.conf

or download manually: 

[John Ripper Rules](/static/security-notes/jonh.conf)

Edit as you see fit, then with sudo cp it to john's directory!

Add the popular rockyou password database [rockyou.txt](https://github.com/praetorian-inc/Hob0Rules/blob/master/wordlists/rockyou.txt.gz) as well!

or here: 

wget  https://github.com/praetorian-inc/Hob0Rules/raw/master/wordlists/rockyou.txt.gz


unzip it:

sudo gunzip rockyou.txt.gz 

check word count:

 wc -l rockyou.txt  

and then in JtR use: john --stdout --wordlist=./rockyou.txt

and send it to a dictionary

john --stdout --wordlist=./rockyou.txt --rules > dict.txt

Now crack it:

john ./passwordComplex

and show the result 

john ./passwordComplex --show

Once you crack it, you can optionally remove the file via this command:

rm ~/.john/john.pot

which will force it to crack from scratch if you enter the same hash again


### Other useful sources and links: 

[Wordlist configurations](https://www.openwall.com/john/doc/RULES.shtml)

[Rock you DB](https://www.kaggle.com/datasets/wjburns/common-password-list-rockyoutxt)

[JtR Tutorial](https://bytesoverbombs.io/cracking-everything-with-john-the-ripper-d434f0f6dc1c)