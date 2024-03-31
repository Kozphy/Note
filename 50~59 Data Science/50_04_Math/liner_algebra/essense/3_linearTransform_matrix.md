# Linear transformation and matrix

## [Source](https://www.youtube.com/watch?v=kYB8IZa5AuE&list=RDCMUCYO_jab_esuFRV4b17AJtAw&index=2&ab_channel=3Blue1Brown)

## intro

In general, linear transformations are functions, with vectors as inputs and vectors as outputs.

$$
\underbrace{
\begin{bmatrix}
5 \\
7
\end{bmatrix} \space{}
}_{\text{input}}
L(\overrightarrow{v})
\space{}
\underbrace{
\begin{bmatrix}
2 \\
-3
\end{bmatrix}
}_{\text{output}}
$$

## Linear transformation(function)

A transformation is linear if it has **two properties**:

- all lines must remain lines, without getting curved.
- Origin must remain fixed in place.

### limits special type of transformation

![Origin_moves](Origin_moves.drawio.svg)
![line_get_curve](line_get_curved.drawio.svg)
![diagonal_lines_curved](diagonal_lines_get_curved.drawio.svg)

> In general, you should think of **linear transformations** as
> **keeping grid lines parallel and evenly spaced**

### Play some transformation

We started off a certain liner combination of i-hat and j-hat and it ends up is that same linear combination of where those two vectors landed.

![play_transformation](play_transformation.drawio.svg)

This means you can deduce where $\overrightarrow{v}$ must go based only on where $\hat{i}$ and $\hat{j}$ each land.

For the transformation shown here ,we can read of that $\hat{i}$ lands on the coordinates (1,-2) and $\hat{j}$ lands on the x-axis over at the coordinates (3,0).

Adding that all together, you can deduce that it has to land on the vector (5,2).

![matrix_transform](matrix_transform.drawio.svg)

> This give us a technique to deduce where any vectors land, as long as we have a record of where $\hat{i}$ and $\hat{j}$ each land without needing to watch  transformation itself.

**In other words, I give you any vector, you can tell me where that vector lands using this formula.**

It is saying that a two dimensional linear transformation is completely described by just four numbers:
$$
\begin{bmatrix}
    3 & 2 \\
    -2 & 1
\end{bmatrix}
$$

which is called two by two matrix ("2x2 matrix")

### if we start the matrix with columns (1,2) and (3,1), what the transformation looks like?

$$
\begin{bmatrix}
    1 & 3 \\
    2 & 1
\end{bmatrix}
$$

1. move $\hat{i}$ to (1,2)
2. move $\hat{j}$ to (3,1)
3. move rest of space to keep grid lines parallel and evenly space

![transform_after](transform_after.drawio.svg)

### if we start the matrix with columns (2,1) and (-2, -1) which is linearly dependent, what the tranformation looks like?

$$
\begin{bmatrix}
    2 & 1 \\
    -2 & -1
\end{bmatrix}
$$

It means that the linear transformation `squishes all of 2D space to the line` where those two vectors sit also known as the one-dimensional spanof those two linearly dependent vectors.

![linear_dependent_matrix](linear_dependent_matrix.drawio.svg)

## sum up

linear transformations are way to move around space such that **grid lines remain parallel and evenly spaced and origin remains fixed.**

Matrices give us a language to describe these transformations

![matrix_tranformation_sum_up](matrix_sum_up.drawio.svg)

where columns represent those coordinates.

![matrix_tranform_sum_up](matrix_transformation_sum_up.drawio.svg)

matrix-vector multiplication is just a way to compute what that transformation does to a given vector.

**Every time you see a matrix, you can interpret it as a certain transformation of space**

**In other words, matrices as transformations of space.**
