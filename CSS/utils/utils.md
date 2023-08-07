# CSS

## CSS Positioning
![CSS Positioning image](images/CSS_Positioning.png)

```html
<div class="parent">
    <div class="child"> Child</div>
</div>
```

```css
.parent{
    position:relative;
    width:100%;
    height:100%;
}   

.child{
    position:absolute;
    width:50px;
    height:50px;
}

.child{
    bottom:0;
    //right:0;
    //top:50%;
    //left:50%;
    //transform: translate(-50%,-50%);
}
```

## Card Caroussel 
![Card Caroussel ](images/Card_Caroussel.png)

```css
.container{
    display:flex;
}
.card{
    position:relative;
    left:0px;
}
.card:not(:first-child){
    margin-left:-50px;
}
.card:hover{
    transform:translateY(-20px);
}
.card:hover ~ .card{
    left:50px;
}
```

## Shake on Invalid Input
![Shake Invalid Input](images/Shake_Invalid_Input.png)
```html
    <input type="text" placeholder="Enter name" pattern="[a-z]*">
```
```css
    input:invalid {
        border : 2px solid red;
        animation : shake 0.2s 2;
    }
    @keyframes shake {
        25% {
            translate : 6px 0;
        }
        50% {
             translate : -6px 0;
        }
        75% {
            translate : 6px 0;
        }
    }
```


# Tools

[UNIVERSE.IO]( https://uiverse.io/)

Open-Source UI elements

