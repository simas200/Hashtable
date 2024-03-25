#include <stdio.h>
#include "../libs/hash/hashtable.h"

int main(){
    struct sim_hash* my_hash = sim_hash_initialize(sizeof(int), sizeof(int));
    printf("%d", (int)sizeof(unsigned char));
    sim_hash_dispoze(my_hash);
    return 0;
}