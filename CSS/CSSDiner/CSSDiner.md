# [CSS Diner](https://flukeout.github.io/)

##  CSS Selectors

Selectors are how you pick which element to apply styles to.
```css
p {
   margin-bottom: 12px;
}
```

Here, the "p" is the selector (selects all <p> elements) and applies the margin-bottom style.


## Type Selector

*A*.
Select elements by their type 
Selects all elements of type *A*. Type refers to the type of tag, so \<div>, \<p> and \<ul> are all different element types.

div selects all \<div> elements


## ID Selector

*#id*.
Select elements with an ID 
Selects the element with a specific id. You can also combine the ID selector with the type selector.

#cool selects any element with id="cool"


## Descendant Selector

*A*  *B*.
Select an element inside another element 
Selects all *B* inside of *A*. *B* is called a descendant because it is inside of another element.

*p  strong* selects all \<strong> elements that are inside of any \<p>

### Combine the Descendant & ID Selectors

*#id  A*
You can combine any selector with the descendent selector.

*#cool span* selects all \<span> elements that are inside of elements with id="cool"


## Class Selector

*.classname*.
Select elements by their class 
The class selector selects all elements with that class attribute. Elements can only have one ID, but many classes.

*.neato* selects all elements with class="neato"

### Combine the Class Selector
*A.className*
You can combine the class selector with other selectors, like the type selector.

ul.important selects all \<ul> elements that have class="important"


## Comma Combinator

*A, B*
Combine, selectors, with... commas!
Thanks to Shatner technology, this selects all *A* and *B* elements. You can combine any selectors this way, and you can specify more than two.

p, .fun selects all \<p> elements as well as all elements with class="fun"


## You can select everything!

*\**
You can select all elements with the universal selector!

p * selects any element inside all \<p> elements.

### Combine the Universal Selector

*A  \**
This selects all elements inside of A.

p * selects every element inside all \<p> elements.


## Adjacent Sibling Selector

*A + B*
Select an element that directly follows another element
This selects all *B* elements that directly follow *A*. Elements that follow one another are called siblings. They're on the same level, or depth.

In the HTML markup for this level, elements that have the same indentation are siblings.

p + .intro selects every element with class="intro" that directly follows a \<p>


## General Sibling Selector

*A ~ B*
Select elements that follows another element
You can select all siblings of an element that follow it. This is like the Adjacent Selector *(A + B)* except it gets all of the following elements instead of one.

A ~ B selects all *B* that follow a *A*


## Child Selector

*A > B*
Select direct children of an element
You can select elements that are direct children of other elements. A child element is any element that is nested directly in another element.

Elements that are nested deeper than that are called descendant elements.

A > B selects all *B* that are a direct children *A*


## First Child Pseudo-selector

*:first-child*
Select a first child element inside of another element
You can select the first child element. A child element is any element that is directly nested in another element. You can combine this pseudo-selector with other selectors.

:first-child selects all first child elements.


## Only Child Pseudo-selector

*:only-child*
Select an element that are the only element inside of another one.
You can select any element that is the only element inside of another one.

span:only-child selects the \<span> elements that are the only child of some other element.


## Last Child Pseudo-selector

*:last-child*
Select the last element inside of another element
You can use this selector to select an element that is the last child element inside of another element.

Pro Tip → In cases where there is only one element, that element counts as the first-child, only-child and last-child!

:last-child selects all last-child elements.


## Nth Child Pseudo-selector

*:nth-child(A)*
Select an element by its order in another element
Selects the nth (Ex: 1st, 3rd, 12th etc.) child element in another element.

:nth-child(8) selects every element that is the 8th child of another element.


## Nth Last Child Selector

*:nth-last-child(A)*
Select an element by its order in another element, counting from the back
Selects the children from the bottom of the parent. This is like nth-child, but counting from the back!

:nth-last-child(2) selects all second-to-last child elements.


## First of Type Selector

*:first-of-type*
Select the first element of a specific type
Selects the first element of that type within another element.

span:first-of-type selects the first span in any element.


## Nth of Type Selector

*:nth-of-type(A)*
Selects a specific element based on its type and order in another element - or even or odd instances of that element.

div:nth-of-type(2) selects the second instance of a div.
.example:nth-of-type(odd) selects all odd instances of a the example class.


## Nth-of-type Selector with Formula

*:nth-of-type(An+B)*
The nth-of-type formula selects every nth element, starting the count at a specific instance of that element.

span:nth-of-type(6n+2) selects every 6th instance of a \<span>, starting from (and including) the second instance.


## Only of Type Selector

*:only-of-type*
Select elements that are the only ones of their type within of their parent element
Selects the only element of its type within another element.

p span:only-of-type selects a \<span> within any \<p> if it is the only \<span> in there.


## Last of Type Selector

*:last-of-type*
Select the last element of a specific type
Selects each last element of that type within another element. Remember type refers the kind of tag, so \<p> and \<span> are different types.

div:last-of-type selects the last \<div> in every element.


## Empty Selector

*:empty*
Select elements that don't have children
Selects elements that don't have any other elements inside of them.

div:empty selects all empty \<div> elements.


## Negation Pseudo-class

*:not(X)*
Select all elements that don't match the negation selector
You can use this to select all elements that do not match selector "X".

:not(#fancy) selects all elements that do not have id="fancy".


## Attribute Selector

*[attribute]*
Select all elements that have a specific attribute
Attributes appear inside the opening tag of an element, like this: \<span attribute="value">. An attribute does not always have a value, it can be blank!

a[href] selects all a elements that have a href="anything" attribute.


## Attribute Selector

*A[attribute]*
Select all elements that have a specific attribute
Combine the attribute selector with another selector (like the tag name selector) by adding it to the end.

[value] selects all elements that have a value="anything" attribute.


## Attribute Value Selector

*[attribute="value"]*
Select all elements that have a specific attribute value
Attribute selectors are case sensitive, each character must match exactly.

input[type="checkbox"] selects all checkbox input elements.


## Attribute Starts With Selector

*[attribute^="value"]*
Select all elements with an attribute value that starts with specific characters

.toy[category^="Swim"] selects elements with class toy and either category="Swimwear or category="Swimming".

### Attribute Ends With Selector

*[attribute$="value"]*
Select all elements with an attribute value that ends with specific characters

img[src$=".jpg"] selects all images display a .jpg image.

### Attribute Wildcard Selector

*[attribute*="value"]*
Select all elements with an attribute value that contains specific characters anywhere
A useful selector if you can identify a common pattern in things like class, href or src attributes.

img[src*="/thumbnails/"] selects all image elements that show images from the "thumbnails" folder.