import calc
import cli

messages = {
    'exit': "Exiting calculator.",
    'help': "\nSimple Calculator is able to calculate single-line expressions.\nExpression is a string: A <OP> B, where:\n  - A, B - operands\n  - <OP> - is one of supported operations: +, -, *, /, //, %%, **.\n\n"
}

cliInstance = cli.CLI(messages, calc.calc)

cliInstance.run()
