#include <iostream>
#include <sstream>
#include <string>
#include "AVLTree.hpp"
std::stringstream ss;
void print(int a, int b) {
    std::cout << "(" << a << ", " << b << ") ";
}
void printStream(int a, int b) {
    ss << "(" << a << ", " << b << ") ";
}
int main() {
    std::cout << "Hello, World!" << std::endl;

    AVLTree<int, int> avlt;

    //3 2 1 4 5 6 7 16 15 14 13 12 11 10 8 9
    int four = 0x04;
    avlt.insert(3, 3);
    //std::clog << "Inserted 3!~ " << std::endl;
    avlt.insert(2, 2);
    //std::clog << "Inserted 2!~ " << std::endl;
    avlt.insert(1, 1);
    //std::clog << "Inserted 1!~ " << std::endl;
    avlt.insert(four, four);
    //std::clog << "Inserted 4!~ " << std::endl;
    avlt.insert(5, 5);
    //std::clog << "Inserted 5!~ " << std::endl;
    avlt.insert(6, 6);
    //std::clog << "Inserted 6!~ " << std::endl;
    avlt.insert(7, 7);
    avlt.insert(16, 16);
    avlt.insert(15, 15);
    avlt.insert(14, 14);
    avlt.insert(13, 13);
    avlt.insert(12, 12);
    avlt.insert(11, 11);
    avlt.insert(10, 10);
    avlt.insert(8, 8);
    avlt.insert(9, 9);

    avlt.inOrderTraverse(print);
    std::cout << std::endl;
    avlt.inOrderTraverse_NR(print);
    std::cout << std::endl;
    avlt.preOrderTraverse(print);
    std::cout << std::endl;
    avlt.postOrderTraverse(print);
    std::cout << std::endl;
    avlt.layerOrderTraverse(print);
    std::cout << std::endl;

   /* std::cout << std::endl;
    avlt.remove(4);
    avlt.inOrderTraverse(print);
    std::cout << std::endl;
    avlt.preOrderTraverse(print);
    std::cout << std::endl;
    avlt.postOrderTraverse(print);
    std::cout << std::endl;
    avlt.layerOrderTraverse(print);
    std::cout << std::endl;

    std::cout << std::endl;
    avlt.remove(7);
    avlt.inOrderTraverse(print);
    std::cout << std::endl;
    avlt.preOrderTraverse(print);
    std::cout << std::endl;
    avlt.postOrderTraverse(print);
    std::cout << std::endl;
    avlt.layerOrderTraverse(print);
    std::cout << std::endl;

    std::cout << std::endl;
    avlt.remove(7);
    avlt.inOrderTraverse(print);
    std::cout << std::endl;
    avlt.preOrderTraverse(print);
    std::cout << std::endl;
    avlt.postOrderTraverse(print);
    std::cout << std::endl;
    avlt.layerOrderTraverse(print);
    std::cout << std::endl;

    std::cout << std::endl;
    avlt.insert(7, 666);
    avlt.inOrderTraverse(print);
    std::cout << std::endl;
    avlt.preOrderTraverse(print);
    std::cout << std::endl;
    avlt.postOrderTraverse(print);
    std::cout << std::endl;
    avlt.layerOrderTraverse(print);
    std::cout << std::endl;

    std::cout << std::endl;
    avlt.insert(6, 666666);
    avlt.inOrderTraverse(print);
    std::cout << std::endl;
    avlt.preOrderTraverse(print);
    std::cout << std::endl;
    avlt.postOrderTraverse(print);
    std::cout << std::endl;
    avlt.layerOrderTraverse(print);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << avlt.find(0) << std::endl;
    avlt.inOrderTraverse(print);
    std::cout << std::endl;
    avlt.preOrderTraverse(print);
    std::cout << std::endl;
    avlt.postOrderTraverse(print);
    std::cout << std::endl;
    avlt.layerOrderTraverse(print);
    std::cout << std::endl;

    std::cout << avlt.size() << std::endl;

    /*AVLTree<int, int> avlt1 = avlt;
    std::cout << std::endl;
    avlt1.inOrderTraverse(print);
    std::cout << std::endl;
    avlt1.preOrderTraverse(print);
    std::cout << std::endl;
    avlt1.postOrderTraverse(print);
    std::cout << std::endl;
    avlt1.layerOrderTraverse(print);
    std::cout << std::endl;

    std::cout << avlt1[10] << std::endl;

    avlt.insert(0, 9);
    avlt1.insert(0, 9);

    ss.str(std::string());
    ss.clear();
    //std::cout << std::endl;
    avlt.layerOrderTraverse(printStream);
    std::string str = ss.str();
    //std::cout << std::endl;
    ss.str(std::string());
    ss.clear();
    //std::cout << ss.str() << std::endl;
    avlt1.layerOrderTraverse(printStream);
    std::string str1 = ss.str();
    //std::cout << str << std::endl;
    //std::cout << str1 << std::endl;
    std::cout << (str == str1) << std::endl;

    ss.str(std::string());
    avlt.preOrderTraverse(printStream);
    //std::cout << std::endl;
    str = ss.str();
    ss.str(std::string());
    avlt1.preOrderTraverse(printStream);
    //std::cout << std::endl;
    str1 = ss.str();
    std::cout << (str == str1) << std::endl;
    ss.str(std::string());
    avlt.postOrderTraverse(printStream);
    //std::cout << std::endl;
    str = ss.str();
    ss.str(std::string());
    avlt1.postOrderTraverse(printStream);
    str1 = ss.str();
    //std::cout << std::endl;
    ss.str(std::string());
    std::cout << (str == str1) << std::endl;
    ss.str(std::string());
    avlt.inOrderTraverse(printStream);
    str = ss.str();
    ss.str(std::string());
    //std::cout << std::endl;
    avlt1.inOrderTraverse(printStream);
    //std::cout << std::endl;
    str1 = ss.str();
    ss.str(std::string());
    std::cout << (str == str1) << std::endl;*/


    /*
     * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
     * 7 4 2 1 3 6 5 13 11 9 8 10 12 15 14 16
     * 1 3 2 5 6 4 8 10 9 12 11 14 16 15 13 7
     * 7 4 13 2 6 11 15 1 3 5 9 12 14 16 8 10
     */

    return 0;
}
