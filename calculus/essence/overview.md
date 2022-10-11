# Overview calculus

## [Source](https://www.youtube.com/watch?v=WUvTyaaNkzM&list=PLZHQObOWTQDMsr9K-rj53DwVRMYO3t5Yr&index=1&ab_channel=3Blue1Brown)

- [Overview calculus](#overview-calculus)
  - [Source](#source)
  - [why the area of circle is $\pi{R}^2$](#why-the-area-of-circle-is-pir2)
  - [Move forward with the approximation](#move-forward-with-the-approximation)
    - [where can this technique use?](#where-can-this-technique-use)
  - [Imagine something like a parabola](#imagine-something-like-a-parabola)
  - [Another stumbling question Derivatives](#another-stumbling-question-derivatives)
  - [Fundamental theorem of calculus](#fundamental-theorem-of-calculus)

## why the area of circle is $\pi{R}^2$

![circle](./asset/essense/overview/circle.drawio.svg)

we know that area is

$$
Area = \pi{R}^2
$$

contemplating this problem and leaving yourself open to exploring the interesting thoughts that come about can actually lead you to a glimpse of three big ideas in calculus: `integrals`, `derivatives`, and the fact that they're `opposites`.

$$
\int_{0}^{R}\frac{dA}{dr}{dr} = A(R)
$$

You try to figure out its area, and after going through a lot, may be you try out the idea of slicing up the circle into many concentric rings. This should seem promising because it respects the symmetry of the circle and math has a tendency to reward you when you respect it's symmetries.

![concentric_rings](./asset/essense/overview/concentric_rings.drawio.svg)

Let's take one of those rings which has some inner radius r that's between 0 and 3.
![inner_radius](./asset/essense/overview/inner_radius_r.drawio.svg)

if we can find a nice expression for the area of each ring like this one, and if we have a nice way to add them all up, it might lead us to an understanding of the full circle's area.

May be you start by imagining `straightening out this ring`.

For simplicity let's just approximate it as rectange, the `width` of which is the circumference of the original ring, which is $2\pi{}r$. It `thickness` is depend on how finely you chopped up the circle in the first place, which was kind of arbitrary. In the spirit of using what will come to be standard calculus notation, let's call that thickness `dr`, for a tiny difference in the radius from one ring to the next.
![straight_out_ring](./asset/essense/overview/straight_out_ring.drawio.svg)

So the inner ring approximate area is

$$
Area \approx{} 2\pi{}rdr
$$

> Note:
> For smaller and smaller choices of dr, this is actually going to be a better and better approximation for that area, since the top and **the bottom sides of this shape (dr)** are going to get **closer and closer to being exactly the same length**.

## Move forward with the approximation

So just to sum up where we are, you've broken up the area of the circle into all of these rings
![breaken_up_ring](./asset/essense/overview/breaken_up_area.drawio.svg)

each of this area is

$$
Area \approx{} 2\pi{}rdr
$$

where the specific value for that inner radius ranges from 0 ,for the smallest ring up to just under 3, for the biggest ring, spread out by whatever the thickness is that you choose for dr-something like 0.1.
![all_inner_ring_spread](./asset/essense/overview/all_inner_ring_spread.drawio.svg)

![all_inner_ring_spread_with_y](./asset/essense/overview/all_inner_ring_speard_with_y.drawio.svg)

For smaller and smaller choices of `dr`, all of their `areas in aggregate` just look like the area under a graph, and that `portion under the graph is just a triangle`.

![all_inner_ring_like_triangle](./asset/essense/overview/all_inner_ring_like_triangle.drawio.svg)

$$
slope = \frac{\Delta{y}}{\Delta{x}} = \frac{rise}{run} = \frac{y_2-y_1}{x_2-x_1} = \frac{{2\pi{}r}}{r} = 2\pi{}\\
$$

Pythagorean Theorem or Distance Formula:

$$
Distance = \sqrt{(\Delta{x})^2 + (\Delta{y})^2} = \sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}
$$

The way that we `transitioned from approximate to something precise` is actually pretty subtle, and `it cuts deep to what calculus is all about`.

### where can this technique use?

![car_travel_velocity](./asset/essense/overview/car_travel_velocity.drawio.svg)

Things like figuring out how far a car has traveled based on its velocity at each point in time. In a case like that you might range through many different points in time and at each one multiply the velocity at that time times a tiny change in time, dt, which would give the corresponding little bit of distance traveled during that little time.

At high level `many of these types of problem turn out to be equivalent to finding the area under some graph`.

## Imagine something like a parabola

What's the area underneath that curve say between values of $x = 0$ and $x = 3$?

![parabola](./asset/essense/overview/parabola.drawio.svg)

Well, it's hard and let me reframe that question in a slightly different way. we'll `fix that left endpoint in place at 0 and let the right endpoint vary`.

Are you able to find a function $A(x)$ that gives you the area under this parabola between 0 and x? `A function A(x) like this is called an integral of` **$x^2$**.

Finding this integral function is genuinely hard and `whenever you come across a genuinely hard question in math a good policy is to not try too hard to get at the answer directly`, since usually you just end up banging your head against a wall.

Instead, play around with the idea, with no particular goal in mind. `Spend some time building up familiarity with the interplay between the function defining the graph`, in this case $x^2$, and the function giving the area.

![interplay](./asset/essense/overview/interplay.drawio.svg)

![tiny_nudge](./asset/essense/overview/tiny_nudge.drawio.svg)

When you slightly increase x by some tiny nudge `dx` look at the resulting change in area represented with this sliver that I'm going to call `dA`(difference in Area) for a tiny difference in area. That `sliver can be pretty well approximated with a rectangle` one whose height is **$x^2$**.

> Note
> The smaller size of that nudge **dx** the more that sliver actually looks like a rectangle.

Now this gives us an interesting way to think about **how $A(x)$ is related to $x^2$**. **A** change to the output of **A** this little `dA` is about equal to **$x^2$**, where **x** is whatever input you stated at, times `dx`, the little nudge to the input that caused **A** to change.

$$
dA \approx{} x^2dx
$$

Or rearrange `dA` divided by `dx`, the ratio of a tiny change in A to the tiny change in x that caused it, is approximately whatever $x^2$ is at that point.

$$
\frac{dA}{dx} \approx{} x^2
$$

In other words, we don't know what $A(x)$ is; that remains a mystery, but we do know a preperty that this mystery must have. When you look at two nearby point for ex 3 and 3.001 consider the change to the output of A between those two points.

The difference between the mystery function evaluated at 3.001 and evaluated at 3. That change devided by the input values, which in this case is 0.001 should be about equal to the value of $x^2$ for the starting input.

$$
\frac{A(3.001) - A(3)}{0.001} \approx{} 3^2
$$

And **this relationship between tiny changes to the mystery function and the values of $x^2$ itself** is true at all inputs not just 3. That doesn't immediately tell us how to find $A(x)$, but it **provides a very strong clue that we can work with**.

## Another stumbling question Derivatives

Here we're stumbling into another big idea from calculus: `"Derivatives"`.

![stubling question](./asset/essense/overview/stubling_question.drawio.svg)

This ratio `dA` divided by `dx` is called the `derivative of A`, or more technically the derivative is whatever `this ratio approaches` as `dx` gets smaller and smaller $dx \rightarrow 0$.

$$
\frac{dA}{dx} \approx f(x)
$$

The loosely speaking it's a measure of how sensitive a function is to small changes in its inputs.

We care about Derivatives is because they help us to solve problems, and in our little exploration here, we already have a slight glimpse of one way that they're used. `They are the key to solving integral questions problem`.

## Fundamental theorem of calculus

This back and forth between integrals and derivatives where the derivative of a function for the area under a graph gives you back the function defining the graph itself is called the "Fundamental theorem of calculus".

$$
A(x) \leftrightarrow \frac{dA}{dx} = x^2
$$

It ties together the two big ideas of integrals and derivatives, and it shows how, in some sense, each one is an inverse of the other.
