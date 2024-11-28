INCORRECT_COMMAND_MESSAGE = 'Failed to parse last command. Please, enter correct command.'
NAN_OPERAND_MESSAGE = 'One of operands is not a number.'
CALCULATION_ERROR = 'Calculation error appeared.'
DIVISION_BY_ZERO_MESSAGE = 'Error: division by zero.'

def calc(command):
    entries = command.split()

    if len(entries) != 3:
        print(INCORRECT_COMMAND_MESSAGE)
        return
    
    a = 0
    b = 0
    answer = 0

    try:
        a = float(entries[0])
        b = float(entries[2])
    except ValueError:
        print(NAN_OPERAND_MESSAGE)
        return

    if abs(a) > (2 ** 31 - 1) or abs(b) > (2 ** 31 - 1):
        print(CALCULATION_ERROR)
        return

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
                return
            answer = a / b
        case '//':
            if b == 0:
                print(DIVISION_BY_ZERO_MESSAGE)
                return
            # По-хорошему, нужно реализовать операцию без ее использования
            answer = a // b
        case '%':
            if b == 0:
                print(DIVISION_BY_ZERO_MESSAGE)
                return
            # По-хорошему, нужно реализовать операцию без ее использования
            answer = a % b
        case '**':
            answer = math.pow(a, b)
        case _:
            print(f'Unknown command {entries[2]}. Please, use only supported OPs.')
            return

    print(f'{command} = {answer:g}')
