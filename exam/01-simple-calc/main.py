import math

WELCOME_MESSAGE = '''
Welcome to Simple Calculator program.
Enter 'h' to see an instruction. 
'''
ASK_FOR_COMMAND_MESSAGE = 'Enter a command: '
INCORRECT_COMMAND_MESSAGE = 'Failed to parse last command. Please, enter correct command.'
EXITING_MESSAGE = 'Exiting calculator.'
CALCULATION_ERROR = 'Calculation error appeared.'
HELP_MESSAGE = "\nSimple Calculator is able to calculate single-line expressions.\nExpression is a string: A <OP> B, where:\n  - A, B - operands\n  - <OP> - is one of supported operations: +, -, *, /, //, %%, **.\n\n"
DIVISION_BY_ZERO_MESSAGE = 'Error: division by zero.'
NAN_OPERAND_MESSAGE = 'One of operands is not a number.'
def UNKNOWN_COMMAND_MESSAGE(op):
    return f'Unknown command {op}. Please, use only supported OPs.'
def ANSWER_MESSAGE(question, answer):
    return f'{question} = {answer:g}'

COMMAND_EXIT = 'q'
COMMAND_HELP = 'h'

print(WELCOME_MESSAGE)

while True:
    command = input(ASK_FOR_COMMAND_MESSAGE)

    if command == COMMAND_EXIT:
        print(EXITING_MESSAGE)
        break

    if command == COMMAND_HELP:
        print(HELP_MESSAGE)
        continue

    entries = command.split()

    if len(entries) != 3:
        print(INCORRECT_COMMAND_MESSAGE)
        continue
    
    a = 0
    b = 0
    answer = 0

    try:
        a = float(entries[0])
        b = float(entries[2])
    except ValueError:
        print(NAN_OPERAND_MESSAGE)
        continue

    if abs(a) > (2 ** 31 - 1) or abs(b) > (2 ** 31 - 1):
        print(CALCULATION_ERROR)
        continue

    match entries[1]:
        case '+':
            answer = a + b
        case '-':
            answer = a - b
        case '*':
            answer = a * b
        case '/':
            if b == 0:
                print(DIVISION_BY_ZERO_MESSAGE)
                continue
            answer = a / b
        case '//':
            if b == 0:
                print(DIVISION_BY_ZERO_MESSAGE)
                continue
            # По-хорошему, нужно реализовать операцию без ее использования
            answer = a // b
        case '%':
            if b == 0:
                print(DIVISION_BY_ZERO_MESSAGE)
                continue
            # По-хорошему, нужно реализовать операцию без ее использования
            answer = a % b
        case '**':
            answer = math.pow(a, b)
        case _:
            print(UNKNOWN_COMMAND_MESSAGE(entries[2]))
            continue

    if abs(answer) > (2 ** 31 - 1):
        print(CALCULATION_ERROR)
        continue

    print(ANSWER_MESSAGE(command, answer))
