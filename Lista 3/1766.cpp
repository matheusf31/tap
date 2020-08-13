#include <bits/stdc++.h>

using namespace std;

typedef struct reindeer {
  char name[110];
  int age;
  int weight;
  double height;
} Reindeer;

int compare(const void *a, const void *b) {
  // aponta para a primeira rena
  Reindeer *aux = (Reindeer *)a;

  // aponta para a segunda rena
  Reindeer *aux2 = (Reindeer *)b;

  // ordena primeiro por peso e caso necessário pela idade, depois altura
  // e por fim pelo nome
  if (aux->weight > aux2->weight)
    return -1;
  else if (aux->weight < aux2->weight)
    return 1;
  else {
    if (aux->age > aux2->age)
      return 1;
    else if (aux->age < aux2->age)
      return -1;
    else {
      if (aux->height > aux2->height)
        return 1;
      else if (aux->height < aux2->height)
        return -1;
      else {
        return strcmp(aux->name, aux2->name);
      }
    }
  }
}

int main() {
  int cases, n, m;
  Reindeer v[1010];

  cin >> cases;

  for (int i = 1; i <= cases; i++) {
    cin >> n >> m;

    for (int j = 0; j < n; j++) {
      cin >> v[j].name >> v[j].weight >> v[j].age >> v[j].height;
    }

    qsort(v, n, sizeof(Reindeer), compare);

    cout << "CENARIO "
         << "{" << i << "}" << endl;

    for (int j = 0; j < m; j++) cout << j + 1 << " - " << v[j].name << "\n";
  }

  return 0;
}