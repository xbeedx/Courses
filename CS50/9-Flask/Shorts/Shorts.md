# Shorts

## [Flask](https://youtu.be/X0dwkDh8kwA)

    Websites that are pure HTML are completely static. The only way we can update the content of our page is to manually open up our source files, edit and save, and then the next time the user visits or refreshes the page they'll get the content. 

    Incorporating Python into the code can make it quite a bit more flexible and introduce a way for our pages to update or be dynamic without requiring our intervention.

    - Data can be passed in via URLs, akin to using HTTP GET.

    - Data can be passed in via HTML forms, as with HTTP POST , but we need to indicate that Flask should respond to HTTP POST requests explicitly. 

    - Flask has a number of functions within its module that will be useful for application developement. 
    

## [AJAX](https://youtu.be/dQcBs4S-wEQ)

    Ajax (Asynchronous Javascript and XML) allows us to dynamically update a webpage even more dynamically.

    Central to our ability to synchronously update our pages is to make use of a special JavaScript object called an XMLHttpRequest.

    - After obtaining your new object, you need to define its onreadystatechange behavior.
        - This is a function (typically an anonymous function) that will be called when the asynchronous HTTP request has completed, and thus  typically defines what is expected to change on your site.

    - XMLHttpRequests have two additional properties that are used to detect when the page finishes loading.
        - The readyState property will change from from 0 (request not yet  initialized) to 1, 2, 3, and finally 4 (request finished, response ready). 
        - The status property will (hopefully!) be 200 (OK).

    - Then just make your asynchronous request using the open() method to define the request and the send() method to actually send it.