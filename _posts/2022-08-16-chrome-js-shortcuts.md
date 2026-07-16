---
title: "Cool Chrome Bookmarklets (Wayback machine, recover passwords, etc)"
layout: post
deescription: "Save time with these useful bookmarklets for chrome - in JS"
image: /static/post-image/dalle_script.png
categories: post
tags:
- JS
- Chrome
- Bookmarklets
- Shortcuts
---

Chrome bookmarklets allow you to type javascript instead of a standard website url. 

We can use this to do some fun and useful things. Either make a new bookmark and in the URL field, type this in, or you should be able to copy and drag the text into the bookmark tab as well (you'll see a plus sign). You can run many (vanilla) JS functions and code within your bookmarklets, but there are some issues with escape characters and formatting. 

You can do most of these commands via chrome extensions or AutoHotKeys, but I prefer bookmarklets because they don't use nearly as much processing power as extensions, are only active once clicked, and are more privacy friendly. This means that you can run a script on a page with a single click, know what code is running and also can see what it logs via the console! 


WARNING: Always audit and review code before running it on your computer! 

Edited: July-16-2026 

<img src="{{ site.url }}{{ page.image }}" alt="Dall-e javascript interpretation Image" width="500" />

The picture is from searching "JavaScript" in Dall-E

## Wayback Machine

Note: Some domains are excluded from the service and some archived webpages will not render properly

* Find archived version of a webpage:

 ```js
javascript: 
void(location.href='https://web.archive.org/web/*/'+escape(location.href.replace(/^https?:\/\//, %27%27).replace(/\/$/, %27%27)));
 ```


* Save current version of page to the archive:

 ```js
javascript:var url = window.location.href;
window.location.href="https://web.archive.org/save/" + url; 
  ```

## News sites

* Escape paywalled articles : 

 ```js
javascript:var url = window.location.href;
window.location.href="https://archive.md/" + url; 
  ```


Note: Some ISPs & DNS servers block this domain and the site may not be compatible with certain news sites. 

## Show password in password form:


 ```js
javascript: var p=r(); function r(){var g=0;var x=false;var x=z(document.forms);g=g+1;var w=window.frames;for(var k=0;k<w.length;k++) {var x = ((x) || (z(w[k].document.forms)));g=g+1;}if (!x) alert('Password not found in ' + g + ' forms');}function z(f){var b=false;for(var i=0;i<f.length;i++) {var e=f[i].elements;for(var j=0;j<e.length;j++) {if (h(e[j])) {b=true}}}return b;}function h(ej){var s='';if (ej.type=='password'){s=ej.value;if (s!=''){prompt('Password found ', s)}else{alert('Password is blank')}return true;}}
  ```


## See deleted reddit content:


 ```js
  javascript: if (location.hostname.match(/reddit\.com$/)) {location.host = "reveddit.com";}
  ```

Note: since reddit changed their API, this may not work well. Original url was abandoned, so I switched to reveddit instead. 

## Webpage auto scroll down with random seed (to pretend we aren't a bot):

 ```js
javascript: var rndInt = Math.floor(Math.random() * 9) + 1;
for(var i = 0; i<10000; i++) 
{
  window.scrollBy(0, 600 + rndInt); console.log(i);
}
 ```


## Remove cookies for a specific website

I wanted to add another useful bookmarklet to erase cache and cookies for any specific website, but unfortunately due to security policies it won't work... 

What you could do alternatively, is to either have it copy the url into your cliboard and then manually open the page... or potentially make your own chrome extension with it.


```js
 javascript: document.location="chrome://settings/siteData?searchSubpage="+document.location.hostname
```

## Force moodle to open PDF preview in new tab rather than open Save As menu

Naviage to a page on moodle with PDF links (that have force download enabled), and then activate the bookmarklet below. 
Note: This change doesn't persist upon refreshing or navigating to a different url on moodle.

```js
javascript:(function(){document.querySelectorAll('a[href*="forcedownload=1"]').forEach(link=>{link.href=link.href.replace('forcedownload=1','forcedownload=0');link.setAttribute('target','_blank');link.setAttribute('rel','noopener noreferrer');});alert('Moodle links updated to open in new tabs!');})();
```


I hope you found these as useful as I do! Please  [tweet me](https://www.twitter.com/aviinfinity) if you have any ideas, comments or feedback!