### English | [中文](/中文介绍)

# 2D-TankWar
2D-TankWar is a 2D C++ game using EasyX library to develop.<br/>

## Table of Contents
- [Development technology](#development-technology)
- [Installation guide](#installation-guide)
- [Module declaration](#module-declaration)
- [Thoughts](#thoughts)
- [Operation instruction](#operation-instruction)
- [Game Screenshot](#game-screenshot)
- [License](#license)

## Development technology <a name="development-technology"></a>
C++ class and the use of object-oriented knowledge, the use of easyX library.<br/>
EasyX library https://easyx.cn/.

## Installation guide <a name="installation-guide"></a>

Since some of the illustrations are set to absolute paths, please install the project on disk D.<br/>

## Module declaration <a name="module-declaration"></a>

The code is written in [c++项目（2019.8）](https://github.com/HeXavi8/2D_TankWar/tree/main/c%2B%2Bproject/c%2B%2B%E9%A1%B9%E7%9B%AE%EF%BC%882019.8%EF%BC%89)<br/>
class rect: describe the information of tank and shell<br/>
class point: describe the information of position<br/>
class graphic: describe the information of pictures<br/>
class object: is base class<br/>
class tank: its inheritance class are mainTank and enemy which describe the information of tank <br/>
class bullet: describes the information of bullet <br/>
class check: check collisions between tank and shell  <br/>

## Thoughts <a name="thoughts"></a>

This is the first project which I spent two weeks on when I learned C++ (also the first programming language I learned) in 2019. After this project, I had a deeper understanding of C++ and learned the application of EasyX library. Due to the limited time, I could not develop more details of the game, such as increasing the levels of the game and enhancing players experience. <br/>

## Operation instruction <a name="operation-instruction"></a>

W - up <br/>
A - left <br/>
S - down <br/>
D - right <br/>
Space- fire <br/>
Esc - exit <br/>
Enter - suspended <br/>

## Game Screenshot <a name="game-screenshot"></a>
![avatar](https://github.com/HeXavi8/2D_TankWar/blob/main/2D_TankWar.png)

## License <a name="license"></a>
[MIT](https://github.com/HeXavi8/2D_TankWar/blob/main/LICENSE)
