# [Frontend](https://roadmap.sh/frontend)

## Internet 

### How does the Internet Work?

The Internet is a global network of computers connected to each other which communicate through a standardized set of protocols.

Visit the following resources to learn more:

- [How does the Internet Work?](https://cs.fyi/guide/how-does-internet-work)
- [The Internet Explained](https://www.vox.com/2014/6/16/18076282/the-internet)
- [How Does the Internet Work?](http://web.stanford.edu/class/msande91si/www-spr04/readings/week1/InternetWhitepaper.htm)
- [Introduction to Internet](https://roadmap.sh/guides/what-is-internet)
- [Learn How the Web Works](https://internetfundamentals.com/)
- [How does the Internet work?](https://www.youtube.com/watch?v=x3c1ih2NJEg)
- [How the Internet Works in 5 Minutes](https://www.youtube.com/watch?v=7_LPdttKXPc)

### What is HTTP?

HTTP is the ```TCP/IP``` based application layer communication protocol which standardizes how the client and server communicate with each other. HTTP follows a classical “Client-Server model” with a client opening a connection request, then waiting until it receives a response. HTTP is a stateless protocol, that means that the server does not keep any data (state) between two requests.

Visit the following resources to learn more:

- [Everything you need to know about HTTP](https://cs.fyi/guide/http-in-depth)
- [What is HTTP?](https://www.cloudflare.com/en-gb/learning/ddos/glossary/hypertext-transfer-protocol-http/)
- [How HTTPS Works …in a comic!](https://howhttps.works/)
- [An overview of HTTP](https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview)
- [HTTP/3 From A To Z: Core Concepts](https://www.smashingmagazine.com/2021/08/http3-core-concepts-part1/)
- [HTTP/3 Is Now a Standard: Why Use It and How to Get Started](https://thenewstack.io/http-3-is-now-a-standard-why-use-it-and-how-to-get-started/)
- [HTTP Crash Course & Exploration](https://www.youtube.com/watch?v=iYM2zFP3Zn0)

### Domain Name

A domain name is a unique, easy-to-remember address used to access websites, such as ‘google.com’, and ‘facebook.com’. Users can connect to websites using domain names thanks to the Domain Name System (DNS).

Visit the following resources to learn more:

- [What is a Domain Name?](https://developer.mozilla.org/en-US/docs/Learn/Common_questions/What_is_a_domain_name)
- [What is a Domain Name? | Domain name vs. URL](https://www.cloudflare.com/en-gb/learning/dns/glossary/what-is-a-domain-name/)
- [A Beginners Guide to How Domain Names Work](https://www.youtube.com/watch?v=Y4cRx19nhJk)

### Hosting

Web hosting is an online service that allows you to publish your website files onto the internet. So, anyone who has access to the internet has access to your website.

Visit the following resources to learn more:

- [What Is Web Hosting? Explained](https://www.youtube.com/watch?v=htbY9-yggB0)
- [Different Types of Web Hosting Explained](https://www.youtube.com/watch?v=AXVZYzw8geg)
- [Where to Host a Fullstack Project on a Budget](https://www.youtube.com/watch?v=Kx_1NYYJS7Q)

### DNS

The Domain Name System (DNS) is the phonebook of the Internet. Humans access information online through domain names, like nytimes.com or espn.com. Web browsers interact through Internet Protocol (IP) addresses. DNS translates domain names to IP addresses so browsers can load Internet resources.

Visit the following resources to learn more:

- [What is DNS?](https://www.cloudflare.com/en-gb/learning/dns/what-is-dns/)
- [Mess with DNS - DNS Playground](https://messwithdns.net/)
- [How DNS works (comic)](https://howdns.works/)
- [DNS and How does it Work?](https://www.youtube.com/watch?v=Wj0od2ag5sk)
- [DNS Records](https://www.youtube.com/watch?v=7lxgpKh_fRY)
- [When to add glue records to DNS settings](https://www.youtube.com/watch?v=e48AyJOA9W8)
- [DNS Records for Newbies - How To Manage Website Records](https://www.youtube.com/watch?v=YV5tkQYcvfg)

### Browsers

A web browser is a software application that enables a user to access and display web pages or other online content through its graphical user interface.

Visit the following resources to learn more:

- [How Browsers Work](https://www.html5rocks.com/en/tutorials/internals/howbrowserswork/)
- [Role of Rendering Engine in Browsers](https://www.browserstack.com/guide/browser-rendering-engine)
- [Populating the Page: How Browsers Work](https://developer.mozilla.org/en-US/docs/Web/Performance/How_browsers_work)
- [How Do Web Browsers Work?](https://www.youtube.com/watch?v=WjDrMKZWCt0)

## HTML

### HTML Basics

HTML stands for HyperText Markup Language. It is used on the frontend 
and gives the structure to the webpage which you can style using CSS 
and make interactive using JavaScript.

Visit the following resources to learn more:

- [W3Schools: Learn HTML](https://www.w3schools.com/html/html_intro.asp) 
    - [Done](../../HTML/W3C/W3C.md)
- [MDN Docs: Getting Started with HTML](https://developer.mozilla.org/en-US/docs/Learn/HTML/Introduction_to_HTML/Getting_started)
- [web.dev: Learn HTML](https://web.dev/learn/html)
- [HTML Full Course - Build a Website Tutorial](https://www.youtube.com/watch?v=pQN-pnXPaVg)
- [HTML Tutorial for Beginners: HTML Crash Course](https://www.youtube.com/watch?v=qz0aGYrrlhU)
- [HTML Cheatsheet](https://htmlcheatsheet.com/)
- [Scaler: HTML](https://www.scaler.com/topics/html)

### Semantic HTML

Semantic element clearly describes its meaning to both the browser and the developer. In HTML, semantic element are the type of elements that can be used to define different parts of a web page such as ```<form>```, ```<table>```, ```<article>```, ```<header>```, ```<footer>```, etc.

Visit the following resources to learn more:

- [Guide to Writing Semantic HTML](https://cs.fyi/guide/writing-semantic-html)
- [W3Schools: Semantic HTML](https://www.w3schools.com/html/html5_semantic_elements.asp)
- [How To Write Semantic HTML](https://hackernoon.com/how-to-write-semantic-html-dkq3ulo)
- [HTML Best Practices – How to Build a Better HTML-Based Website](https://www.freecodecamp.org/news/html-best-practices/)
- [Semantic HTML: What It Is and How It Improves Your Site](https://blog.hubspot.com/website/semantic-html)
- [Semantic Markup](https://html.com/semantic-markup)
- [Semantic HTML - web.dev](https://web.dev/learn/html/semantic-html/)

### Forms and Validations

Before submitting data to the server, it is important to ensure all required form controls are filled out, in the correct format. This is called client-side form validation, and helps ensure data submitted matches the requirements set forth in the various form controls.

Visit the following resources to learn more:

- [MDN Web Docs: Client-side form validation](https://developer.mozilla.org/en-US/docs/Learn/Forms/Form_validation)
- [Learn Forms by web.dev](https://web.dev/learn/forms/)
- [W3Schools: JavaScript Form Validation](https://www.w3schools.com/js/js_validation.asp)

 Accessibility

Web accessibility means that websites, tools, and technologies are designed and developed in such a way that people with disabilities can use them easily.

Visit the following resources to learn more:

- [Developing for Web Accessibility by W3C WAI](https://www.w3.org/WAI/tips/developing/)
- [Accessibility Tutorial](https://www.w3schools.com/accessibility/index.php)
- [A Complete Guide To Accessible Front-End Components](https://www.smashingmagazine.com/2021/03/complete-guide-accessible-front-end-components/)
- [Complete Playlist on Accessibility](https://youtube.com/playlist?list=PLNYkxOF6rcICWx0C9LVWWVqvHlYJyqw7g)
- [MDN Accessibility](https://developer.mozilla.org/en-US/docs/Web/Accessibility)
- [Accessibility for Developers by Google](https://web.dev/accessibility)
- [Web Accessibility by Udacity](https://www.udacity.com/course/web-accessibility--ud891)
- [Accessibility as an Essential Part of the Inclusive Developer Experience](https://thenewstack.io/accessibility-as-an-essential-part-of-the-inclusive-developer-experience/)

### Basics of SEO

SEO or Search Engine Optimization is the technique used to optimize your website for better rankings on search engines such as Google, Bing etc.

Visit the following resources to learn more:

- [Google Search Central — SEO Docs](https://developers.google.com/search/docs)
- [SEO Guide](https://github.com/seo/guide)
- [8 Must-Know SEO Best Practices For Developers](https://neilpatel.com/blog/seo-developers/)
- [SEO for Developers](https://medium.com/welldone-software/seo-for-developers-a-quick-overview-5b5b7ce34679)
- [Complete SEO Course for Beginners](https://www.youtube.com/watch?v=xsVTqzratPs)
- [SEO Expert Course](https://www.youtube.com/watch?v=SnxeXZpZkI0)
- [Learning SEO](https://learningseo.io/)

## CSS

### CSS Basics

CSS or Cascading Style Sheets is the language used to style the frontend of any website. CSS is a cornerstone technology of the World Wide Web, alongside HTML and JavaScript.

Visit the following resources to learn more:

- [W3Schools — Learn CSS](https://www.w3schools.com/css/)
     - [Done](../../CSS/W3C/W3C.md)
- [web.dev — Learn CSS](https://web.dev/learn/css/)
- [freeCodeCamp — Responsive Web Design](https://www.freecodecamp.org/learn/responsive-web-design/)
- [Learn to Code HTML & CSS](https://learn.shayhowe.com/html-css/building-your-first-web-page/)
- [CSS Crash Course For Absolute Beginners](https://www.youtube.com/watch?v=yfoY53QXEnI)
- [HTML and CSS Tutorial](https://www.youtube.com/watch?v=D-h8L5hgW-w)
- [CSS Masterclass - Tutorial & Course for Beginners](https://www.youtube.com/watch?v=FqmB-Zj2-PA)

### Making layouts

Float, grid, flexbox, positioning, display and box model are some of the key topics that are used for making layouts. Use the resources below to learn about these topics:

Visit the following resources to learn more:

[Learn and Practice Flexbox](https://flexboxfroggy.com/)
[Game for learning CSS Grid](https://cssgridgarden.com/)
[All about Floats](https://css-tricks.com/all-about-floats/)
[Positioning Types: How Do They Differ?](https://css-tricks.com/absolute-relative-fixed-positioining-how-do-they-differ/)
[The Box Model](https://developer.mozilla.org/en-US/docs/Learn/CSS/Building_blocks/The_box_model)
[The CSS Display Property](https://www.freecodecamp.org/news/the-css-display-property-display-none-display-table-inline-block-and-more/)
[A Complete Guide to Flexbox](https://css-tricks.com/snippets/css/a-guide-to-flexbox)
[A Complete Guide to Grid](https://css-tricks.com/snippets/css/complete-guide-grid)
[Learn CSS Grid - Course](https://cssgrid.io/)
[Learn CSS Grid for free](https://scrimba.com/learn/cssgrid)
[Get on the Grid at Last with the CSS Grid Layout Module](https://thenewstack.io/get-grid-last-css-grid-template-markup/)

### Responsive Web Design

Responsive Web Designing is the technique to make your webpages look good on all screen sizes. There are certain techniques used to achieve that e.g. CSS media queries, percentage widths, min or max widths heights etc.

Visit the following resources to learn more:

[Responsive Web Design](https://www.w3schools.com/css/css_rwd_intro.asp)
[Learn Responsive Design](https://web.dev/learn/design/)
[The Beginner’s Guide to Responsive Web Design](https://kinsta.com/blog/responsive-web-design/)
[The guide to responsive web design in 2022](https://webflow.com/blog/responsive-web-design)
[5 simple tips to making responsive layouts the easy way](https://www.youtube.com/watch?v=VQraviuwbzU)
[Introduction To Responsive Web Design](https://www.youtube.com/watch?v=srvUrASNj0s)

## JavaScript

### Learn the basics

JavaScript allows you to add interactivity to your pages. Common examples that you may have seen on the websites are sliders, click interactions, popups and so on.

Visit the following resources to learn more:

[W3Schools – JavaScript Tutorial](https://www.w3schools.com/js/)
[The Modern JavaScript Tutorial](https://javascript.info/)
[JavaScript Crash Course for Beginners](https://youtu.be/hdI2bqOjy3c?t=2)
[Build a Netflix Landing Page Clone with HTML, CSS & JS](https://youtu.be/P7t13SGytRk?t=22)