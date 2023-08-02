#include<iostream>
#include<memory>

class classe {
    public:
    int valor = 0;
};

std::unique_ptr<classe> situacao(std::unique_ptr<classe> pointer){
    std::cout << "Aqui devia ser deletado"<<'\n';
    return pointer;
}

int main(){
    auto pointer = std::make_unique<classe>();
    pointer->valor = 10;
    std::cout << "pointer " << pointer->valor << '\n';// << "unico " << unico->valor << '\n';
    pointer = situacao(std::move(pointer));
    pointer->valor = 20;
    std::cout << "pointer " << pointer->valor << '\n';// << "unico " << unico->valor << '\n';
    return 0;

    
}
