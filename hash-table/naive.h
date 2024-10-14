#define KEY_MAX_LEN 10
#define MAP_CAPACITY 10

typedef struct {
    char *key;
    float value;
} NaiveKV;

typedef struct {
    NaiveKV data[MAP_CAPACITY];
} NaiveKVs;

NaiveKVs *create_naive_hash_map(void);
void add_naive_hash_map(NaiveKVs *map, char *key, float value);
float get_naive_hash_map(NaiveKVs *map, char *key);
void print_naive_hash_map(NaiveKVs *map);
