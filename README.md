 ![Language](https://img.shields.io/badge/language-C-blue) [![Contributors][contributors-shield]][contributors-url] [![Forks][forks-shield]][forks-url] [![Stargazers][stars-shield]][stars-url] [![Issues][issues-shield]][issues-url] [![MIT License][license-shield]][license-url] [![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />

<p align="center">
  <h3 align="center">Betweenness Centrality</h3>
  <p align="center">
    Using modified Floyd-Warshall and modified BFS 
    <br />
    <a href=https://github.com/vineeths96/Betweenness-centrality><strong>Explore the repository»</strong></a>
    <br />
    <br />
    <a href=https://github.com/vineeths96/Betweenness-centrality/blob/master/Problem%20Statement.pdf>View Problem Statement</a>
    </p>




</p>

> tags : betweenness centrality, ventrality, graphs, graph theory



<!-- ABOUT THE PROJECT -->

## About The Project

This program performs the betweenness centrality calculation in networks represented as undirected graphs. Betweenness centrality is a measure of the importance of a particular node in a network. The entire program is written in three files - `client.c`, `header.c`, and `implement.c`. Comments have been added frequently to help in understanding the logic behind implementation. The program expects the user to save all the graphs to be processed in the 'graphs' directory in edge list format and to input the filename during execution. The user is provided with the option of either displaying the betweenness centrality on screen or to save it in a file in 'results' directory (by calling appropriate function). The execution time vs number of vertices of random graphs for different probabilities is stored in 'results' directory. Refer [Problem statement](./Problem%20Statement.pdf) file for detailed information.

The program when run requests the user to input the number of vertices and the name of file from which graph has to be extracted. The graph has to be stored in 'graphs' folder and has to be stored in edge list format. On successful extraction, an undirected graph with the specified number of vertices and edges will be created. This program calculates the betweenness centrality values using Floyd Warshall algorithm as well as n-BFS algorithm. The BC_mat_FW and BC_mat_BFS arrays are updated with the betweenness centrality values of vertices after BC_Floyd_Warshall() and BC_BFS() calls respectively. Both the functions return the time taken for execution of the algorithm. The user is given the option to either print the betweenness centrality values on screen or store it to a file in 'results' directory.

### Built With

This project was built with 

* C
* Ubuntu 18.04.1 
* gcc version 7.4.0



<!-- GETTING STARTED -->

## Getting Started

Clone the repository into a local machine using

```shell
git clone https://github.com/vineeths96/Betweenness-centrality
```

### Instructions to run

Open the terminal, make the program and run it. 

```shell
make
./a.out
```

Enter the values from the file (or custom values) as requested during execution of the program.

### Testcases

The [graphs](./graphs) folder contains the 5 test cases. Provide the file name of graph during execution. 



<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Vineeth S - vs96codes@gmail.com

Project Link: [https://github.com/vineeths96/Betweenness-centrality](https://github.com/vineeths96/Betweenness-centrality)




<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/vineeths96/Betweenness-centrality.svg?style=flat-square
[contributors-url]: https://github.com/vineeths96/Betweenness-centrality/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/vineeths96/Betweenness-centrality.svg?style=flat-square
[forks-url]: https://github.com/vineeths96/Betweenness-centrality/network/members
[stars-shield]: https://img.shields.io/github/stars/vineeths96/Betweenness-centrality.svg?style=flat-square
[stars-url]: https://github.com/vineeths96/Betweenness-centrality/stargazers
[issues-shield]: https://img.shields.io/github/issues/vineeths96/Betweenness-centrality.svg?style=flat-square
[issues-url]: https://github.com/vineeths96/Betweenness-centrality/issues
[license-shield]: https://img.shields.io/badge/License-MIT-yellow.svg
[license-url]: https://github.com/vineeths96/Betweenness-centrality/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/vineeths

