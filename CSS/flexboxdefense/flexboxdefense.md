# [flexboxdefense](http://www.flexboxdefense.com/)


Flexbox container has a main axis and a cross axis.
![flexbox-row](http://www.flexboxdefense.com/images/flexbox-row-e5f974eec786eaf8b7997706f91f0c01.png)


## justify-content

**justify-content** positions a container's items along the main axis and accepts the following values:
- **flex-start**: group items at the start of a container's main axis
- **flex-end**: group items at the end of the main axis
- **center**: group items in the center of the main axis
- **space-between**: evenly distribute items along the main axis such that the first item aligns at the start and the final item aligns at the end
- **space-around**: evenly distribute items along the main axis such that all items have equal space around them


## align-items

**align-items** positions a container's items across its cross axis and accepts the following values:

- **flex-start**: align items across the start of a container's cross axis
- **flex-end**: align items across the end of the cross axis
- **center:** align items across the center of the cross axis
- *baseline:* align items such that their baselines line up
- *stretch:* stretch items such that they span the entire cross axis


## flex-direction

**flex-direction** defines the directional layout of the main and cross axes in the flex container.

For example, although the main axis lays out horizontally and the cross axis lays out vertically by default, **flex-direction** can rotate the axes such that the main axis lays out vertically and the cross axis lays out horizontally. Here's what this looks like:
![flexbox-column](http://www.flexboxdefense.com/images/flexbox-column-a0e8dc099b07e1cfd6eaa6da2525cf54.png)

Accordingly, flex-direction accepts the following values:
- **row:** lay out the main axis from left to right
- **row-reverse:** lay out the main axis from right to left
- **column:** lay out the main axis from top to bottom
- **column-reverse:** lay out the main axis from bottom to top


## order

The **order** property defines the order in which an item appears in the flex container and accepts both positive and negative integer values. All flex items begin with a default order of 0, so an item with an order greater than 0 will be repositioned relative to items still set to their default orders.

- #: position an item relative to the other items in the container


## align-self

To vertically position individual towers, use **align-self**, which accepts the same values as align-items.

- **flex-start**: align items across the start of a container's cross axis
- **flex-end**: align items across the end of the cross axis
- **center:** align items across the center of the cross axis
- *baseline:* align items such that their baselines line up
- *stretch:* stretch items such that they span the entire cross axis

