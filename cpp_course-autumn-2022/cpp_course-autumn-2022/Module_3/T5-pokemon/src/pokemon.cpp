#include "pokemon.hpp"

PokemonCollection::PokemonCollection(PokemonCollection collection, PokemonCollection collection2) {
    collection.pokemons_.merge(collection2.pokemons_);
    collection.SortById();
    collection.pokemons_.unique();
    pokemons_ = collection.pokemons_;
}

void PokemonCollection::Add(const std::string& name, size_t id) {
    std::pair<std::string, size_t> pair;
    pair.first = name;
    pair.second = id;
    pokemons_.emplace_back(pair);
}

bool PokemonCollection::Remove(const std::string& name, size_t id) {
    std::list<std::pair<std::string, size_t>>::iterator x = pokemons_.begin();
    bool asdf = false;
    for (auto y : pokemons_) {
        if(y.first == name && y.second == id) {
            asdf = true;
            pokemons_.erase(x);
            break;
        }
        x++;
    }
    return asdf;
}

void PokemonCollection::Print() const {
    for (auto& x : pokemons_) {
        std::cout << "id: " << x.second << ", name: " << x.first << std::endl;
    }
}

void PokemonCollection::SortByName() {
    pokemons_.sort();
}

void PokemonCollection::SortById() {
    pokemons_.sort([](const std::pair<std::string, size_t> &x, const std::pair<std::string, size_t> &y) {
            return x.second < y.second;
        }
    );
}

//self note: remember to delete main
