---
title: 'VSCode Tip: How to convert phone numbers to "tel:" links with one go!'
layout: post
deescription: "I built a site for a client who has several store branches. The way they provided the information was lacking, and I didn't want to go through each branch to correct the information."
# image: /static/post-image/hevc.png
categories: post
tags:
- REGEX
- VSCODE
- HTML
---


---

For the phone number example, the original table looks like this:
<tr class="loc">
<td>Branch Name</td>
<td>Address</td>
<td>Region</td>
<td>01–2345678</td>
</tr>
And I want to change the phone number to look like this:
<td><a href="tel:01–2345678>01–2345678</a></td>
In HTML, this allows the user to call a phone number by just clicking the link!

---

Turns out, with visual studio code, there is a regex find and replace command which is super helpful!
Hit Ctrl + F on windows -> Now click on the box with* icon
Now you can enter regex into the find field!
I used this regex code "((\d[\d\-.]*){9,})" to find all phone numbers on the page!
Then I wanted to do something more elaborate with those details.
In the replace section, you can use "macros" to modify the information regarding that specific entry.
In the replace field, I entered "<a href="tel:$1">$1</a>"
where $1 is the "macro" referencing the actual data captured by our regex code. 
It should look like this:
Now, once you are done… you can either replace each one individually by clicking 
or all at once with the button to the right of that. I advise you to replace one entry first, make sure it does the intended action… if not you can always undo the change with Ctrl + Z. But if it works, then you can replace all!