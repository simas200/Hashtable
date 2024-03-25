#ifndef SIM_HASHTABLE
#define SIM_HASHTABLE

struct sim_hash{
    int size;
    int full;
    struct record** records;
    int key_size;
    int val_size;
};

struct sim_hash* sim_hash_initialize(int key_size, int value_size);
int sim_hash_dispoze(struct sim_hash* hash);
void* sim_hash_lookup(struct sim_hash* hash, void* key);
int sim_hash_set(struct sim_hash* hash, void* key, void* value);
int sim_hash_remove(struct sim_hash* hash, void* key);

#endif /* SIM_HASHTABLE */