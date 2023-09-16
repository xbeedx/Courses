# Shorts 

# [Internet Primer](https://www.youtube.com/watch?v=04GztBlVo_s)

## IP Address

- In order for your machine to uniquely identify itself on the Internet, it needs an address.
    - This way, it can send information out and also receive information back to the correct location. 

- The addressing scheme used by computers is known as IP Addressing. 

- As originally developed, the IP-Addressing scheme would effectively allocate  a unique 32-bit address to each device hoping to connect to the internet. 

- Instead of representing these 32-bit addresses as hexadecimal, we represent them as four clusters of 8-bits using decimal notation. 

        - w.x.y.z

- Each of these clusters can be a non negative value in the range [0,255].

-  If each IP Address is 32 bits, that means there are roughy 4 billion addresses to give out.

- In recent years, we've been slowly phasing out this old scheme (IPv4) and replacing it with a new scheme (IPv6) hat assigns computers 128-bit addresses, instead of 32-bit addresses. 

        - s,t,u,v,w,x,y,z

- Each of s,t,u,v,w,x,y and z is represented by 1 to 4 hexadecimal digits in the range [0,ffff].

## DHCP 

- Somewhere between the computer and the Internet at large exists a Dynamic Host Configuration Protocol (DHCP) server, whose role is to assign IP addresses to devices.

- Prior to the widespred promulgation of DHCP, the task of assigning IP addresses fell to a system administrator, who would need to manually assign such addresses. 

## DNS

- The Domain Name Serer (DNS) exists to help us translate IP addresses to more memorable names that are more human-comprehensible.

- Large DNS server systems are more like aggregators, collecting smaller sets of DNS information and pooling them together, updating frequently. 

## Access Points 

- The IP address is assigned to a router, whose job is to act as a traffic cop that allows data request from all of the devices on your local network to be processed through a single IP address. 

- Modern home networks onsist of access points hat combine a router, a modem, a switch and other technologies together into a single device.

- Modern business networks or large-scale wide-area networks (WANs) till frequently have theseas separated devices to allow the size of their network to scale more easily. 


# [Internet Protocole (IP)](https://youtu.be/A1g9SokDJSU)

- "The Internet" is really an intercnnected network comprised of smaller networks woven together and agreeing to communicate with one another.

- The Internet Protocol (IP) is the set of rules that governs how data is sent from one network to another over the Internet.

- Networks are not directly connected to each other at all, and rely on routers to distribute communications. 
    - On a small scale, this configuration may actually be more inefficient than just having direct connections.
    - On a large scale, this configuration can dramatically reduce the costs of the network infrastructure.

- In reality, the data isn't being sent as one huge block

- Any slowdown that was caused by sending such  large amount of data would ave a ripple effect that would throttle the network for all the other users.

- As such, another crucial part of IP is splittng data into packets. 

- IP is also known as a connectionless protocol. There is not necessarily  defined path from the sender tot he receuver, and vice versa. 

- This means that in response to the traffic that might be "clogging" up one particular path through the Internet, some packets can be "re-routed" round the traffic jam to follow the most optimal path, based on he current state of the network. 

- Another side effect of being conenctionless is that delivery annot be guaranteed to be consistent. 

# [Transmission  Control Protocol (TCP)](https://youtu.be/GP7uvI_6uas)

- If the Internet Protocol is thought of as the protocol for getting information from a sending machine to a receiving machine, then Transmission COntrol Protocol can be thought of as directing the transmitted packet to the correct program on the receiving machine.

- It is importantto be able to identify both where the reciever is and what the packet s for, so TCP and IP are almost an inseparable pair: TCP/IP

- Each program/utility/service on a machine is assigned a port number. Coupled with an IP address , we can now uniquely identify a specific program on a specific machine. 

- The other thing that TCP is crucial for is guaranteeing delivery of packet, which IP alone does not do.

- TCP does this by including information about how many packets should the receiver expect to get, and in What order, and transmitting that information alongside the data.

- Some ports are so commonly used that they have been standardized across all computers.
    - FTP (file transfer) uses port 21
    - SMTP (e-mail) uses port 25
    - DNS uses port 53
    - HTTP (web browsing) uses port 80
    - HTTPS (secure web browsing) uses port 443

- Steps of the TCP/IP process:
    1. When a programm goes to send data, TCP breaks t into smaller chunks and communicates those packets to the computer's network software, adding a TCP layer onto the packet. 
    2. IP routes the individual packets  from sender to receiver; this info is part of the IP layer surrounding the packet.
    3. Whent he destination computer gets the packet, TCP looks at the header to see which program it belongs to; and since the routes packets take may differ, TCP also must present those packets to the destination program in the proper order.

- If at any point long the way a router delivering information using the Internet Protocol dropped a packet, TCP would use additional information inside the headers to request that the sender pass along the extra packet so it could complete assembly.

- After the packets haeva arrived, TCP ensures they are organized he correct order and can then be reassembled into the inted unit of data and delivered to the correct service.

# [Hypertext Transfer Protocol (HTTP)](https://youtu.be/4axL8Gfw2nI)

- In addition to protocols tht dictate how information is ommunicated from machine to machine and application to application, it is frequently the case that the application itself has as a system of rules for how to interpret the data that was sent.

- HTTP is one of such example of an application layer protocol, which specifically dictates the format by which clients request web pages from a server, and the format via which servers return information to clients.

- Other application layer protocols include:
    - File Transfer Protocol: FTP
    - Simple Mail Transfer Protocol: SMTP 
    - Data Distribution Service: DDS
    - Remote Desktop Protocol: RDS
    - Extensible Message and Presence Protocol: XMPP

- A line of the form 
```
    method requets-target http-version 
```
```
    GET requets-target HTTP/1.1 
```

- Is a simple exemple of an HTTP requets line, a crucial part of an overall HTTP request that a client may make to a server.

- The host name is also included as a separate line fo the overall HTTP request.

- Taken together , the host name and the request arget from the request line specify a specific ressource being sought.

- Based on whether the ressoruce exists and hether the server is empowered to deliver that ressource pursuant t he client's request, a number of status codes can result.

- A status code is part of the first line that a server will use to respond to  HTTP request.
```
    http-version status
```

| Class | Code | Text | Comments |
|-------|------|------|----------|
|Success|200|OK|All is well, valid request and response|
|Redirection|301|Moved Permanently|Page is now at a new location; automatic redirects built into most browsers.|
||302|Found|Page is now  a new location temporarily.|
|Client Error|401|Unauthorized|Page typically requires login credentials.|
||403|Forbidden|Server will not allow this request.|
||404|Not Found|Server cannot found what was asked for.|
|Server Error|500|Internal Server Error|Generic Server failure in responding to the otherwise-valid request.|

# [HTML](https://youtu.be/YK78KhMf7bs)

- HTML (Hyper Text Markup Language) is a fundamental omponent for every website.

- HTML is a language but it's not a programming language . It lacks concepts of variables , logic, functions, and the like.

- Rather, it's a markup language, using angle-bracket enclosed tags to sementically define the struture of a web page, causing the plain text inside of sets of tags to be interpreted by web browsers in different ways. 

## Common HTML tags 

- \<b>, ›\</b>
    - Text between these tags will be rendered in blodface by the browser.

- \<i>,\</i>
    - Text between these tags will be rendered in italics by the browser.

- \<u>,\</u>
    - text between these tags will be rendered underlined by the browser.

- \<p>,\</p>
    - Text between these tags will be rendered as a paragraph by the browser, with space above and below.

- \<hX>,\</hX>
    - X = 1,2,3,4,5 or 6
    - Text between these tags will be rendered as an X-level section header.

- \<ul>,\</ul>
    - Demarcate the beginning and end of an unordered list.

- \<ol>,\</ol>
    - Demarcate the beginning and end of an ordered list.

- \<li>,\</li>
    - Demarcate list items with an ordered or unordered list.

- \<table>,\</table>
    - Demarcate the beginning and end of a table definition.

- \<tr>,\</tr>
    - Demarcate the beginning and end of a row within a table.

- \<td>,\</td>
    - Demarcate the beginning and end of a column Within a row within a table.

- \<form>,\</form>
    - Demarcate the beginning and end of an HTML form.

- \<div>,\</div>
    - Demarcate the beginning and end of an arbitrary HTML page division.

- \<input name=X type=Y/>
    - Define a field within an HTML form. X is a unique identifier for that field. Y is what type of data it accepts.

- \<a href=X>,\</a>
    - Creates a hyperlink to web page X, with the text between he tags rendered.

- \<image src=X .../>
    - Another self-closing tag for displaying an image located at X, with possible additional attributes (such as specifying width and height).

- \<!DOCTYPE HTML>
    - Specififc to HTML5, lets the browser know that's the standard you're using.

- \<!--,-->
    - Demarcate the beginning and end of an HTML comment.

- It is important that the HTML written is well-formed. Every tag opened should be closed, and tags should be closed in reverse order of whent hey were opened.

- Unlike C, HTML will not necessarily fail with syntax errors.

# [CSS](https://youtu.be/Ub3FKU21ubk)

- CSS (Cascading Style Sheets) is another language we use to when constructing websites.
    - If HTML is used to organize the content that we aim to display on our pages, then CSS is the tool we use to customize our website's look and feel.

- Like HTML, CSS is not a programming language; it lacks logic. Rather, it is a styling language and its syntax describes how certain attributes of HTML elements should be modified.

- A style sheet is constructed by identifying a selector (in the last example, body) and then an open curly brace to indicate the beginning of the style sheet for that selector.

- In between the curly brace you place a list of key-value pairs of style properties and values for those properties, each declaration ending with a semicolon.

- Then a closing curly brace terminates the style sheet.

## Common CSS properties

- border: style color width
    - Applies a border of the specified color, width, and style (e.g., dotted, dashed, solid, ridge...).

- background-color: [keyword | #<6-digit hex>]
    - Sets the background color. Some colors are pre-defined in CSS.

- color: [keyword | #<6-digit hex>]
    - Sets the foreground color (usually text).

- font-size: [absolute size | relative size]
    - Can use keywords (xx-small, medium...), fixed points (10pt, 12pt...), percentage (80%, 120%), or base off the most recent font size (smaller, larger).

- font-family: [font name | generic name]
    - Certain "web safe" fonts are pre-defined in CSS.

- text-align: [left | right | center | justify]
    - For displaying text.

- Your selectors don't have to apply only to HTML tag categories. There also exist ID selectors and class selectors.

- A tag selector will apply to all elements with a given HTML tag.
```css
h2
{
font-family: times;
color: #fefefe;
}
```

- An ID selector will apply only to an HTML tag with a unique identifier.
```css
#unique
{
border: 4px dotted blue;
text-align: right;
}
```

- A class selector will apply only to those HTML tags that have been given identical "class" attributes.
```css
.students
{
background-color: yellow;
opacity: 0.7;
}
```

- Style sheets can be written directly into your HTML.
    - Place them within <style> tags within your page's head.

- Style sheets can also be written as separate CSS files and then linked in to your document.
    - Use <link> tags within your page's head to accomplish this.

# [JavaScript](https://youtu.be/Z93IaNfavZw)

- JavaScript is a modern programming language that is derived from the syntax at C.

- It has been around just about as long as Python, having been invented a few years later, in 1995.

- JavaScript, HTML, and CSS make up the three languages defining most of the user experience on the web.

- To start writing JavaScript, open up a file with the .js file extension.

- No need for any code delimiters like you may be familiar with if you've used a language like PHP. Our website will know that our file is JavaScript because we'll explicitly tell it as much in an HTML tag.

- Unlike Python which runs server-side, JavaScript applications run client-side, on your own machine.

## Including JavaScript in your HTML

- Just like CSS with \<style> tags, you can directly write your JavaScript between \<script> tags.

- Just like CSS with \<link> tags, you can write your JavaScript in separate files and link them in by using the src attribute of the \<script> tag.

## Variables

- JavaScript variables are similar to Python variables.
    - No type specifier.
    - When a local variable is first declared, preface with the var keyword.

## Conditionals and Loops

- All of the old favorites from C are still available for you to use.

## Functions

- All functions are introduced with the function keyword.

- JavaScript functions, particularly those bound specifically to HTML elements, can be anonymous-you don't have to give them a name!

## Arrays

- Declaring an array is pretty straightforward.
```js
var nums = [1, 2, 3, 4, 5];
```

## Objects

- JavaScript has the ability to behave in a few different ways, but in particular it can behave as an object-oriented programming language.

- An object is sort of analogous to a C structure.

- C structures contain a number of fields or members, which we might also call properties.
    - But the properties themselves can not ever stand on their own.

- Objects, meanwhile, have properties but also methods, or functions that are inherent to the object, and mean nothing outside of it.
    - Thus, like properties can methods not ever stand on their own.

## Functions (redux)

- Arrays are a special case of an object (in fact, everything in JavaScript is a special case of an object), and has numerous
 methods that can applied to them:
    - array size(), array pop(), array push(x), array. shift();

- There is also a method for arrays called map (), which can be used to apply a function to all elements of an array.
    - A great situation to use an anonymous function

## Events

- An event in HTML and JavaScript is a response to user interaction with the web page.
   - A user clicks a button, a page has finished loading, a user has hovered over a portion of the page, the user typed in an input field.

- JavaScript has support for event handlers, which are callback functions that respond to HTML events.
   - Many HTML elements have support for events as an attribute.

- We can write a generic event handler in JavaScript, creating an event object, that will tell us which of these two buttons was clicked.


# [Document Object Model (DOM)](https://youtu.be/LKWJpgvfH3U)

- JavaScript objects are incredibly flexible, and can contain various fields, even when those fields are other objects.
 
- The document object is one way of employing this paradigm, whereby that object organizes the entire contents of a web page.

- By organizing an entire page into a JavaScript object, we can manipulate the page's elements programmatically.

- The document object itself, as well as all of the objects contained within it, have a number of properties and a number of methods that can be used to drill down to a very specific piece of your website.

- By resetting those properties or calling certain methods, the contents of our web pages can change without us needing to refresh the page.


## DOM Properties

| DOM Property | Description  |
|-------|------|
| innerHTML | Holds the HTML inside a set of HTML tags. |
| nodeName |  The name of an HTML element or element's attribute. |
|   id |       The "id" attribute of an HTML element. |
|parentNode | A reference to the node one level up in the DOM. |
|childNodes | An array of references to the nodes one level down in the DOM. |
|attributes |  An array of attributes of an HTML element. |
|  style |  An object encapsulating the CSS/HTML styling of an element. |



## DOM Methods

| DOM Method | Description  |
|-------|------|
| getElementById(id) | Gets the element with a given ID below this point in the DOM. |
| getElementsByTagName(tag) | Gets all elements with the given tag below this point in the DOM. |
| appendChild(node) | Add the given node to the DOM below this point.|


## jQuery

- Because DOM manipulation is so common with JavaScript, and because the JavaScript to do so can get quite lengthy, people wanted alternatives.

- jQuery is a popular open-source library, released in 2006, that is designed to simplify client-side scripting (such as DOM manipulations).

```js
$('#colorDiv').css('background-color', ‘green');
```

