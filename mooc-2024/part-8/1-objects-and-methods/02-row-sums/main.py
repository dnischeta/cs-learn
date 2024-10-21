def row_sums(matrix):
    for row in matrix:
        row.append(sum(row))

    return matrix

print(row_sums([[1,2], [3,4]]))