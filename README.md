# ekzecutor

![EK](https://raw.githubusercontent.com/libetl/ekzecutor/master/src/pic/spsc.bmp "EK")

The EKzecutor is a programing language to abstract the concepts of algorithms, it is a formal language for structured data manipulation and a language for a mathematical and theorical insight.

## Summary

Made for learning purposes, it allows to go beyond distinctions of any kind (programing language, type declaration, keywords thanks to the very poor syntax).

As it was invented for lectures, there is not any strict definition of the language outside of this project.

It is possible to make some changes on numbers, lists and arrays. The aim of this program is to see the traces of these algorithms.

A K program is divided into recursive functions. They consist in an init clause, several cases, with at least one terminal.

## Example

```
How to find the maximum value in an array :

 Initialisation MAXIMUM(T, i, n, max)=  MAXIMUM(T, 2, |T|, T[1])
 Différents cas i ⇐ n ^ T[i] >  max ⇒ MAXIMUM(T, i, n, max) = MAXIMUM(T, i + 1, n, T[i])
                i ⇐ n ^ T[i] ⇐ max ⇒ MAXIMUM(T, i, n, max) = MAXIMUM(T, i + 1, n, max)
                i >  n               ⇒ MAXIMUM(T, i, n, max) = max
 Fin
```
