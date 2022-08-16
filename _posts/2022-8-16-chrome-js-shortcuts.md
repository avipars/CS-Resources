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
---

Chrome bookmarklets allow you to type javascript instead of a standard website url. 

We can use this to do some fun and useful things. Either make a new bookmark and in the URL field, type this in, or you should be able to copy and drag the text into the bookmark tab as well (you'll see a plus sign).

<img src="{{ site.url }}{{ page.image }}" alt="Dalle JS Image" width="500" />


## Wayback Machine and site archive: 

* Find old version of page:

 ```js
javascript:void(location.href='https://web.archive.org/web/*/'+escape(location.href.replace(/^https?:\/\//, %27%27).replace(/\/$/, %27%27)));
 ```


* Save current version of page to the archive:

 ```js
javascript:var url = window.location.href;
window.location.href="https://web.archive.org/save/" + url; 
  ```


* Escape paywalled article: 

 ```js
javascript:var url = window.location.href;
window.location.href="https://archive.ph/" + url; 
  ```


## Show password in password form:


 ```js
javascript: var p=r(); function r(){var g=0;var x=false;var x=z(document.forms);g=g+1;var w=window.frames;for(var k=0;k<w.length;k++) {var x = ((x) || (z(w[k].document.forms)));g=g+1;}if (!x) alert('Password not found in ' + g + ' forms');}function z(f){var b=false;for(var i=0;i<f.length;i++) {var e=f[i].elements;for(var j=0;j<e.length;j++) {if (h(e[j])) {b=true}}}return b;}function h(ej){var s='';if (ej.type=='password'){s=ej.value;if (s!=''){prompt('Password found ', s)}else{alert('Password is blank')}return true;}}
  ```


## See deleted reddit content:

 ```js
  javascript: document.location = document.URL.replace('reddit.com','removeddit.com');
  ```


## Webpage auto scroll down with random seed (to pretend we aren't a bot):

 ```js
javascript: var rndInt = Math.floor(Math.random() * 9) + 1;for(var i = 0; i<10000; i++) {window.scrollBy(0, 600 + rndInt); console.log(i); }
  ```