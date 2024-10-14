matrix = []
width = 0
height = 0

with open('matrix.txt', encoding='utf-8') as f:
    for line in f:
        line = line.replace('\n', '')
        nums = line.split(',')
        width = len(nums)
        matrix += [*map(int, nums)]
        height = height + 1

def matrix_sum(matrix, width, height):
    sum = 0
    for i in range(height):
        for j in range(width):
            sum += matrix[i * width + j]
    return sum

def matrix_max(matrix):
    return max(matrix)

def row_sum(matrix, width, height, row_idx):
    sum = 0
    for i in range(width):
        sum += matrix[row_idx * width + i]
    return sum

print(matrix_sum(matrix, width, height))
print(matrix_max(matrix))
print(row_sum(matrix, width, height, 1))