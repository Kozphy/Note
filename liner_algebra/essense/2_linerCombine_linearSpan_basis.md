# liner combine, liner span, basis

## [Source](https://www.youtube.com/watch?v=k7RM-ot2NWY&list=PLZHQObOWTQDPD3MizzM2xVFitgF8hE_ab&index=2&ab_channel=3Blue1Brown)

## base x, y coordinate vectors

- the `one pointing to the right with length 1` which is commonly called "i-hat" or unit vector in x-direction.

- the `one pointing to the straight up with length 1` which is commonly called "j-hat" or the unit vector in the y-direction

- $\hat{i}$ and  $\hat{j}$ are the "basis vectors" of the xy coordinate system

$$
\text{i-hat or unit vector of x-direction} = \hat{i} \newline
$$

$$
\text{j-hat or unit vector of y-direction} = \hat{j} \newline
$$

![base_vector_xy](../asset/base_x_y_vector.drawio.svg)

## liner combination

The `liner` come from if you fix one of those scalars, and let the other one change its value freely the tip of the resulting vector draws a straight line.

Any time you're **scaling** `two vectors` and **adding** them together which is called a `linear combination` of those two vectors.

![linear_combination](../asset//linear_combination.drawio.svg)

### terminology "span"

The `span` is asking set of all possible vectors that you can reach with a liner combination of a given pair of vectors.

![vector_span](../asset/vector_span.drawio.svg)

## Vector vs Points

The point at the tip of vector, where I want you thinking about that vector with its tail on the origin.

- Thinking individual vectors as arrows
- Thinking set of vectors as points

### if the infinite vector is no line up the span is

- The span of most pairs of vectors ends up being the entire `infinite sheet of two-dimensional space` leaving the arrows out of it.
![no_line_up_span](../asset//no_line_up_vector.drawio.svg)

### if the infinite vector is line up the span is

- just `line`.
![line_up_span](../asset/line_up_vector.drawio.svg)

## What does the span of two 3d vectors look like?

### if you take two vectors in 3d space

Adding the scaled vector to liner combination of two vector which tip will trace out some kind of flat cheet, cutting through the origin of three-dimensional space.

![2d_vector_flat_sheet](../asset/3d_2vector_flat_sheet.drawio.svg)

### if you take three vectors in 3d space

if you just randomly choose a `thrid vector which not sitting on the span of those first two vector` since it's points to separate direction, it unlocks access to every possible three-dimensional vector.

As you scale that new third vector, it moves arounds that span sheet of the first two, sweeping it through all of space.

$$
a\overrightarrow{v} + b\overrightarrow{w} + c\overrightarrow{u}
$$

![3d_vector_in_3d_space](../asset/3d_3vector.drawio.svg)

## terminology of "Linearly dependent"

When you have `multiple vectors and you could remove it without reducing the span`.

Another way of phrasing that would be to say that one of the vectors can be expressed as a linear combination.

![Linear_dependent](../asset//linear_dependent.drawio.svg)

## terminology of "Linearly independent"

if `each vector really add another dimension` to the span.

![Linear_independent](../asset//linear_indepenent.drawio.svg)

## Technical definition of basis

The **basis** of a vector space is a set of **linearly independent** vectors that **span** the full space.
