#Você recebe um tempo t e precisa contar quantas chamadas foram feitas nos últimos 3000 milissegundos.

typedef struct {
    int times[10000];
    int inicio;
    int fim;
} RecentCounter;

RecentCounter* recentCounterCreate() {
    RecentCounter* rc = malloc(sizeof(RecentCounter));
    rc->inicio = rc->fim = 0;
    return rc;
}

int recentCounterPing(RecentCounter* obj, int t) {
    obj->times[obj->fim++] = t;

    while (obj->times[obj->inicio] < t - 3000) {
        obj->inicio++;
    }

    return obj->fim - obj->inicio;
}

void recentCounterFree(RecentCounter* obj) {
    free(obj);
}
