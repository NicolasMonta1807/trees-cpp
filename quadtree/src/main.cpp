#include <iostream>
#include <fstream>
#include <queue>
#include "QuadNode.h"
#include "QuadTree.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Verificación de argumentos
    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }

    // Creación del QuadTree
    QuadTree<int> *image = new QuadTree<int>();
    queue<int> data;

    fstream file(argv[1], ios::in);
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }

    // Lectura de datos
    int height, width;
    char color;
    file >> height;
    file >> width;

    while (file.get(color))
    {
        if (color == '\n')
            continue;
        data.push((color - '0'));
    }
    image->fillTree(&data);

    // Creación de la matriz
    int **matrix = new int *[height];
    for (int i = 0; i < height; i++)
        matrix[i] = new int[width];

    // Llenado de la matriz
    image->getRoot()->fillMatrix(matrix, height, 0, width, 0);

    // Guardar en archivo
    fstream file2(argv[2], ios::out);
    file2 << "P1" << endl;
    file2 << "#Creada por Espitia G. y Montañez N. usando QuadTrees" << endl;
    file2 << width << " " << height << endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 1; j++)
            file2 << matrix[i][j] << " ";
        file2 << matrix[i][width - 1] << endl;
    }

    // Liberación de memoria
    for (int i = 0; i < height; i++)
        delete[] matrix[i];
}