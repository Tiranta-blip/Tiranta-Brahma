<!DOCTYPE html>
<html>
<head>
<title>Quantum</title>
<style>
body {
  background-image: url("https://yt3.ggpht.com/Tz6w0unnfnAUs02x6LOF5qWM3d_dutoAy5ecqfaFGV4_77AgbiswRCQe0FKbvcJ2jvJCsYXgWwaA1g=s1524-nd-v1"); /* Replace with your image path */
  background-repeat: no-repeat; /* Prevents image from repeating */
  background-size: cover; /* Ensures image covers the entire background */
  background-attachment: fixed; /* Keeps the background image fixed when scrolling */
}
</style></head>
<script src=“tiranta.js”></script>
<body bgcolor=“black”>
<h2>quantum</h2>

Closed. This question does not meet Stack Overflow guidelines. It is not currently accepting answers.
This question does not appear to be about a specific programming problem, a software algorithm, or software tools primarily used by programmers. If you believe the question would be on-topic on another Stack Exchange site, you can leave a comment to explain where the question may be able to be answered.
Closed 6 years ago.
Improve this question
I have a html file that titled test.html this is the file:

<!DOCTYPE html>
<html>
<body onload="document.getElementById('saveForm').click();">
<form method="post" enctype="multipart-form-data" name="my_form" onsubmit="clearTextBoxCounter()" action="http://xxxxx" >

  <input type=hidden name=teks value=><center><b>KIRIM SMS GRATIS</b></center><br><br>
Nomer HP:<br />
  <input class="field text small" type="text" maxlength="20" name="Phonenumbers" value="085642383165"/>
  <br />

<br />
Isi Pesan:<br />
  <textarea rows="5" cols="20" onKeyPress=check_length(this.form); onKeyDown=check_length(this.form); name=Text >testing pesan 2</textarea>
<br />

<input id="saveForm" class="btTxt" type="submit" value="KIRIM" name="TOMBOL" />

</body>
</html>
as you can see when the file is loaded it automatically clicks the submit button, and redirects it to http://xxxxxx how can I run this html file from terminal? I'm using this on openwrt with webserver installed on it.
htmllinux
Share
Improve this question
Follow
asked Jan 3, 2015 at 22:14
orlea's user avatar
orlea
63522 gold badges66 silver badges1313 bronze badges
not familiar with openwrt, doesn't it have lynx (the command line browser)? – 
mihai
 Commented Jan 3, 2015 at 22:21
3
Start researching headless browsers. Picking one for you and walking you through installing one up is out-of-scope for this site. – 
user229044
♦
 Commented Jan 3, 2015 at 22:24 
Also, you probably don't want to do this. You should describe your actual problem for us, because writing an entire HTML document with embedded JavaScript for automatically submitting the form, just to programatically issue POST requests from the command line, is the worst solution to that problem. There's probably a one-line CURL command that can do this for you. – 
user229044
♦
 Commented Jan 3, 2015 at 22:26
Add a comment

Report this ad
9 Answers
Sorted by:

 
73


For those like me, who have reached this thread because they want to serve an html file from linux terminal or want to view it using a terminal command, use these steps:-

If you want to view your html using a browser:
Navigate to the directory containing the html file
If you have chrome installed,

Use

google-chrome <filename>.html
Or Use

firefox <filename>.html
If you want to serve html file and view it using a browser
Navigate to the directory containing the html file
And Simply type the following on the Terminal:-

pushd <filename>.html;  python3 -m http.server 9999; popd;
Then click the I.P. address 0.0.0.0:9999 OR localhost:9999 (Whatever is the result after executing the above commands). Or type on the terminal :-

firefox 0.0.0.0:9999
Using the second method, anyone else connected to the same network can also view your file by using the URL: 0.0.0.0:9999
Share
Improve this answer
Follow
edited Aug 26, 2023 at 23:44
Community's user avatar
CommunityBot
111 silver badge
answered Jun 30, 2017 at 19:04
shubham agarwal's user avatar
shubham agarwal
84777 silver badges33 bronze badges
Sign up to request clarification or add additional context in comments.

4 Comments

Add a comment

desmond13
Over a year ago
this is the fastest way IMHO to get what I wanted.

1

Reply


Collado
Over a year ago
Other users in the network can access said webpage if they navigate to <your-machine-ip>:9999. The 0.0.0.0 IPv4 address is a placeholder for INADDR_ANY as seen on this manage. Its meaning roughly being: "let the server listen on every interface on the machine". You can obtain your machine's IPv4 address if you issue ip addr on linux machines, ifconfig -a on BSD systems (such as macOS) or ifconfig /all on Windows boxes.

0

Reply


MAZ
Over a year ago
What is the purpose of &lt in this context? Could someone please explain?

1

Reply


Prav
Over a year ago
@AMS it stands for the < (less than) sign. It meant <filename>.html

0

Reply

Add a comment
 
30


This works :

browsername <filename>
Example: google-chrome index.html

enter image description here
Share
Improve this answer
Follow
edited Jun 20, 2020 at 9:12
Community's user avatar
CommunityBot
111 silver badge
answered Apr 5, 2019 at 9:00
Anush Ganiga's user avatar
Anush Ganiga
31933 silver badges44 bronze badges
Comments

Add a comment
 
24


You could always use the Lynx terminal-based web browser, which can be got by running $ sudo apt-get install lynx.

With Lynx, I believe the file can then be viewed using lynx <filename>
Share
Improve this answer
Follow
edited Apr 17, 2018 at 1:37
answered Jan 3, 2015 at 22:24
Blayzeing's user avatar
Blayzeing
74644 silver badges1212 bronze badges
1 Comment

Add a comment

Quentin
Over a year ago
Lynx will not execute the JavaScript

4

Reply

 
3


Skip reading the html and use curl to POST whatever form data you want to submit to the server.
Share
Improve this answer
Follow
answered Jan 3, 2015 at 22:27
Robert Calhoun's user avatar
Robert Calhoun
5,23311 gold badge4343 silver badges3636 bronze badges
Comments

Add a comment
 
3


It is possible to view a html file from terminal using lynx or links. But none of those browswers support the onload javascript feature. By using lynx or links you will have to actively click the submit button.
Share
Improve this answer
Follow
answered Jan 3, 2015 at 22:30
Henrik Carlqvist's user avatar
Henrik Carlqvist
1,16855 silver badges77 bronze badges
Comments

Add a comment
 
2


I think what you want is simply this.

Open the terminal

Navigate to the directory containing the HTML file

And simply type: browse (your file name) without the parentheses of course.

This will run your HTML file in Firefox browser.
Share
Improve this answer
Follow
edited Jan 22, 2019 at 6:55
Prakash Pazhanisamy's user avatar
Prakash Pazhanisamy
98311 gold badge1515 silver badges2525 bronze badges
answered Jan 22, 2019 at 6:46
Afaque's user avatar
Afaque
3933 bronze badges
Comments

Add a comment
 
-2


You can make the file accessible via a web server then you can use curl or lynx
Share
Improve this answer
Follow
answered Jan 3, 2015 at 22:24
RoboTamer's user avatar
RoboTamer
3,54322 gold badges4141 silver badges4444 bronze badges
2 Comments

Add a comment

Gilles Quénot
Over a year ago
Why not just on the client side ? -_-

1

Reply


RoboTamer
Over a year ago
Would be a long line of curl code. Webserver is simpler and easier to debug

0

Reply

 
-4


python -mhtmllib test.html or curl http://www.comanyname.com/somepage.html|python -mhtmllib -
Share
Improve this answer
Follow
answered Sep 11, 2016 at 12:55
Jesse Hwong's user avatar
Jesse Hwong
111 bronze badge
2 Comments

Add a comment

HaveNoDisplayName
Over a year ago
Add some explanation

4

Reply


abarisone
Over a year ago
Please edit with more information. Code-only and "try this" answers are discouraged, because they contain no searchable content, and don't explain why someone should "try this".

0

Reply

 
-4


You can open an HMTL file from Linux/Unix terminal by using Firefox <filename>.html.
Share
Improve this answer
Follow
edited Jan 30, 2024 at 21:09
soundflix's user avatar
soundflix
3,1111212 gold badges1919 silver badges3939 bronze badges
answered Jan 11, 2017 at 8:51
Kiran J's user avatar
Kiran J
1311 bronze badge
Comments

Add a comment
Protected question. To answer this question, you need to have at least 10 reputation on this site (not counting the association bonus). The reputation requirement helps protect this question from spam and non-answer activity.
Start asking to get answers

Find the answer to your question by asking.

Ask question
Explore related questions
htmllinux
See similar questions with these tags.
The Overflow Blog
Live from the OpenAI forum: Learning to code in the age of AI
Vibe coding needs a spec, too
Featured on Meta
Community Asks Sprint Announcement - October/November 2025
We’re releasing our proactive anti-spam measure network-wide
Opinion-based questions alpha experiment on Stack Overflow

Report this ad
Community activity
Last 1 hr
USERS ONLINE ACTIVITY
7730 users online
 14 questions
 20 answers
 63 comments
 160 upvotes
Popular tags
python
php
java
javascript
c#
html
Popular unanswered question
How to fix this：Type alias is not generic or already specialized
python
User avatar
Shadow Kas
1
30 minutes ago
Linked

1
Capture the image in background and save in folder in PHP
Related

5469
How can I validate an email address in JavaScript?
5098
How can I horizontally center an element?
3136
How can I recursively find all files in current and subfolders based on wildcard matching?
3453
How can I change an element's class with JavaScript?
2018
How can I set the default value for an HTML <select> element?
2760
How do I create an HTML button that acts like a link?
3080
How can I know which radio button is selected via jQuery?
2533
How can I make a div not larger than its contents?
2325
How do you parse and process HTML/XML in PHP?
Hot Network Questions

Late-night transfer from SHA to PVG airport (single ticket)
What is this mysterious icon?
Given dark energy is described by a cosmological constant does the acceleration of the universe approach a constant?
Short Layover in SFO between two international flights
Don't all roads lead to heat death?
Reconstructing the quadrilateral
How big was the nuclear-triggered tsunami at Moruroa in July 1979?
Do there exist English translations of Arabic mathematics in the middle ages?
Are Christians themselves the inheritance in Ephesians 1:11-14?
Does wine importer Bill DeBlasio's email responding to the Times of London constitute impersonation?
How to manually delete a curve edge?
Add capacitor between Source and Drain on N-MOSFET
Macro for missing word(s)
Overnight layover at DXB: Can I leave the airport on a single-ticket itinerary with Emirates?
How do you decide the correct trace width in PCB design?
Why does the Java collator for hungarian locale mix E and É?
Do I need a transit visa through Munich, while travelling DEL - MUC - YYZ
Template for function with N inputs
How does Dispel Magic work for targets with an ongoing magical effect depending on the distance from the source of the effect?
Where did Jesus go that the disciples could not follow Him at that moment?
Stack characters closer than their outline
Odd approach pattern?
Arduino IDE formatting quirk with nested lists
Is there any extant documentation for the MTS fmt formatting program?

STACK OVERFLOW

Questions
Help
Chat
PRODUCTS

Teams
Advertising
Talent
COMPANY

About
Press
Work Here
Legal
Privacy Policy
Terms of Service
Contact Us
Cookie Settings
Cookie Policy
STACK EXCHANGE NETWORK

Technology
Culture & recreation
Life & arts
Science
Professional
Business
API
Data
Blog
Facebook
Twitter
LinkedIn
Instagram
Site design / logo © 2025 Stack Exchange Inc; user contributions licensed under CC BY-SA . rev 2025.10.31.36208
By continuing to use this website, you agree Stack Exchange can store cookies on your device and disclose information in accordance with our Cookie Policy. By exiting this window, default cookies will be accepted. To reject cookies, select an option from below.
Necessary cookies only
Customize settings
</body>
</html>