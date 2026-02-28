*This project has been created as part of the 42 curriculum by mledda, tlopez.*

# push_swap

## Description

push_swap est un projet de tri qui consiste à trier une pile de nombres entiers en utilisant un ensemble limité d'opérations, avec deux piles : **a** et **b**.

Le but est de trier la pile `a` en ordre croissant en utilisant le moins d'opérations possible.

Les opérations disponibles sont :
- `sa`, `sb`, `ss` — swap du premier et second élément
- `pa`, `pb` — push du sommet d'une pile vers l'autre
- `ra`, `rb`, `rr` — rotation vers le haut
- `rra`, `rrb`, `rrr` — rotation vers le bas

## Instructions

### Compilation

```bash
make
```

### Utilisation

```bash
./push_swap [nombres] [flags]
```

**Exemples :**
```bash
./push_swap 3 1 4 1 5 9
./push_swap 42 0 -7 100 --bench
./push_swap 5 2 8 --simple
```

**Flags disponibles :**
- `--bench` — affiche les statistiques (nombre d'opérations, désordre, stratégie choisie)
- `--simple` — force le tri simple (O(n²))
- `--medium` — force le bucket sort (O(n√n))
- `--complex` — force le radix sort (O(n log n))
- `--adaptive` — sélection automatique selon le désordre (comportement par défaut)

### Nettoyage

```bash
make clean   # supprime les .o
make fclean  # supprime les .o et le binaire
make re      # recompile tout
```

## Algorithmes

Trois algorithmes sont implémentés, sélectionnés automatiquement selon le niveau de désordre de la pile :

**Selection sort (O(n²))** — utilisé quand le désordre est faible (< 20%). On cherche le minimum, on le remonte en haut de `a` et on le pousse dans `b`. Une fois qu'il reste 3 éléments dans `a`, on les trie manuellement avec `sort_three`, puis on repousse tout dans `a`. Simple et efficace pour les petites stacks ou les stacks quasi-triées.

**Bucket sort (O(n√n))** — utilisé pour un désordre moyen (20%–50%). On découpe les éléments en "buckets" par plage d'index, on pousse dans `b` bucket par bucket, puis on repousse dans `a` en cherchant toujours le max de `b`. Bon compromis entre nombre d'opérations et complexité.

**Radix sort (O(n log n))** — utilisé quand le désordre est élevé (> 50%). On trie bit par bit sur les index des éléments. Pour chaque bit, les éléments avec un `0` vont dans `b`, ceux avec un `1` restent dans `a` via `ra`. Ensuite on repousse tout dans `a`. Très efficace pour les grandes stacks.

L'indexation préalable des éléments (remplacer les valeurs par leur rang 0..n-1) permet à radix sort et bucket sort de fonctionner indépendamment des valeurs réelles.

## Ressources

- [Visualiseur push_swap](https://github.com/o-reo/push_swap_visualizer) — pour visualiser les opérations
- [Radix sort expliqué](https://en.wikipedia.org/wiki/Radix_sort)
- [Notion de désordre / inversions](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics))

**Utilisation de l'IA :** Claude (Anthropic) a été utilisé pour déboguer la gestion des erreurs dans `ft_atoi_mod` et `build_stack`, notamment les problèmes de valeurs sentinelles (retourner `1` ou `0` comme code d'erreur quand ces valeurs sont des entiers valides).