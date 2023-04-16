#include <iostream>
#include <vector>

//puramente para estudos, não faz nada de util

//classe de modelo
class pixel{

private:
    int r, b, g;
public:
    pixel(int red, int blue, int green){

        this->r = red;
        this->b = blue;
        this->g = green;

    }

    int getRed(){
        return this->r;
    }

    int getBlue(){
        return this->b;
    }

    int getGreen(){
        return this->g;
    }

};

//unique_ptr pois cada imagem possui a propriedade
//exclusiva sobre seu conjunto de pixels
//então requer o uso do unique_ptr
class imagem{

private:
    int width;
    int height;
    std::vector<std::unique_ptr<pixel>> pixels;
public:
    imagem(int w, int h){

        //ação de criar cada pixel para o tamanho da imagem
        for(std::size_t i{0} ; i < w * h ; i+=1){

            pixels.push_back(std::make_unique<pixel>(0,0,0));

        }

    }

    std::unique_ptr<pixel>& getSegmentData(int x, int y){

        return pixels.at(x+y);

    }

};

class janela{
private:
    std::shared_ptr<imagem> img;
public:
    janela(std::shared_ptr<imagem> im){
        this->img = im;
    }

    void trocarImagem(std::shared_ptr<imagem> newImage){
        this->img = newImage;
    }
};

int main() {
    std::shared_ptr<imagem> img = std::make_shared<imagem>(256,195);
    //esta recuperando um ponto especifico na matrix de pixels
    std::cout << img->getSegmentData(50,95)->getGreen();
    janela jnl(img);
    return 0;
}
