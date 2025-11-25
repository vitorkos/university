def difference_engine(y):
    n = len(y)
    table = [y]
    for i in range(n-1):
        row = []
        for j in range(n-i-1):
            d = table[i][j+1] - table[i][j]
            row.append(d)
        table.append(row)
    return table

def next_value(diff_table):
    s = 0.0
    for row in diff_table:
        s += row[-1]
    return s

def n_value_table(diff_table, steps=1):
    tbl = [row[:] for row in diff_table]
    for _ in range(steps):
        tbl[-1].append(tbl[-1][-1])
        for r in range(len(tbl) - 2, -1, -1):
            tbl[r].append(tbl[r][-1] + tbl[r + 1][-1])
    return tbl

def polinomio(x, coeficientes):
    soma, i = 0, 0
    grau = len(coeficientes)-1
    while(i<=grau):
        soma += coeficientes[i] * (x**(grau-i))
        i += 1
    return soma


if __name__ == '__main__':

    coeficientes = [2, 3, 4, 5]
    x = [0, 0.1 ,0.2, 0.3, 0.4]
    y = [polinomio(x, coeficientes) for x in x]

    idx = difference_engine(y)
    nxt_val = next_value(idx)

    steps_to_09 = int(round((1.6 - x[-1]) / (x[1] - x[0])))
    diff_to_09 = n_value_table(idx, steps=steps_to_09)
    y_09_machine = diff_to_09[0][-1]

    print("X values:", x)
    print("Y values:", y)
    print("\nDiff table:")
    for i, diff in enumerate(idx):
        print(f"Diff {i}: {diff}")
    print(f"Next value: {nxt_val}")
    print(f"Value 9: {y_09_machine}")
