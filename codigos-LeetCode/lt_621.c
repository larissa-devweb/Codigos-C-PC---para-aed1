#include <stdio.h>
#include <stdlib.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    int count[26] = {0}; // cria um array para contar cada letra 'A' a 'Z'

    // conta a frequência de cada tarefa
    for(int i = 0; i < tasksSize; i++) {
        count[tasks[i] - 'A']++;
    }

    // encontra a frequência máxima
    int maxCount = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] > maxCount)
            maxCount = count[i];
    }

    // conta quantas tarefas têm a frequência máxima
    int maxTasks = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] == maxCount)
            maxTasks++;
    }

    // calcula o intervalo mínimo baseado na fórmula:
    // (maxCount - 1) * (n + 1) + maxTasks
    int partCount = maxCount - 1; // número de "partes" entre tarefas mais frequentes
    int partLength = n + 1;       // tamanho de cada parte (cooldown + 1)
    int emptySlots = partCount * partLength; // slots necessários
    int totalTime = emptySlots + maxTasks;   // adiciona as tarefas com frequência máxima

    // retorna o maior entre o tamanho real das tarefas e o tempo calculado
    // porque se tiver muitas tarefas, elas podem preencher os slots
    return totalTime > tasksSize ? totalTime : tasksSize;
}
