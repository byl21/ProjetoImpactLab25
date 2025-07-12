#include <iostream>
#include <fstream>
// Este programa cria uma imagem no formato PPM (Portable Pixmap).
// A imagem terá 70 pixels de largura e 50 pixels de altura.
// A metade esquerda da imagem será preenchida com a cor vermelha
// e a metade direita será preenchida com a cor azul.

int main() {
    // Define as dimensões da imagem
    const int image_width = 70;
    const int image_height = 50;

    // Cria e abre o arquivo de imagem de saída.
    // O "./images/" assume que existe uma pasta chamada "images" no mesmo diretório do executável.
    // Se a pasta não existir, o arquivo não será criado.
    std::ofstream image_file("./images/Imagem_50_50.ppm");

    // Verifica se o arquivo foi aberto com sucesso
    if (image_file.is_open()) {
        // --- Cabeçalho do arquivo PPM ---
        // P3: Indica que as cores são em formato RGB ASCII.
        // image_width image_height: As dimensões da imagem.
        // 255: O valor máximo para cada componente de cor (R, G, B).
        image_file << "P3\n";
        image_file << image_width << " " << image_height << "\n";
        image_file << "255\n";

        // --- Corpo da Imagem (Pixels) ---
        // Itera sobre cada linha (da cima para baixo)
        for (int y = 0; y < image_height; ++y) {
            // Itera sobre cada pixel em uma linha (da esquerda para a direita)
            for (int x = 0; x < image_width; ++x) {
                // Pinta a primeira metade (esquerda) da imagem de vermelho
                if (x < image_width / 2) {
                    // Escreve o trio RGB para vermelho: (255, 0, 0)
                    image_file << "255 0 0 ";
                }
                // Pinta a segunda metade (direita) da imagem de azul
                else {
                    // Escreve o trio RGB para azul: (0, 0, 255)
                    image_file << "0 0 255 ";
                }
            }
            // Adiciona uma nova linha no arquivo ao final de cada linha de pixels da imagem
            // Isso ajuda a manter o arquivo PPM legível.
            image_file << "\n";
        }

        // Fecha o arquivo após escrever todos os pixels
        image_file.close();
        std::cout << "Imagem 'Imagem_50_50.ppm' criada com sucesso na pasta ./images/" << std::endl;
    } else {
        // Informa o usuário caso não seja possível abrir/criar o arquivo
        std::cout << "Erro ao abrir o arquivo. Verifique se a pasta './images/' existe." << std::endl;
    }

    return 0;
}
