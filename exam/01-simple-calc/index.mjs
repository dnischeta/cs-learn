import Readline from 'node:readline/promises';
import { stdin, stdout } from 'node:process';

process.on('unhandledRejection', (err) => {
    console.log(err);
});

const WELCOME_MESSAGE = `
Welcome to Simple Calculator program.
Enter 'h' to see an instruction. 
`;
const ASK_FOR_COMMAND_MESSAGE = 'Enter a command: ';
const INCORRECT_COMMAND_MESSAGE = 'Failed to parse last command. Please, enter correct command.';
const EXITING_MESSAGE = 'Exiting calculator.';
const CALCULATION_ERROR = 'Calculation error appeared.'
const HELP_MESSAGE = "\nSimple Calculator is able to calculate single-line expressions.\nExpression is a string: A <OP> B, where:\n  - A, B - operands;\n  - <OP> - is one of supported operations: +, -, *, /, //, %%, **.\n\n";
const DIVISION_BY_ZERO_MESSAGE = 'Error: division by zero.';
const UNKNOWN_COMMAND_MESSAGE = (op) => `Unknown command ${op}. Please, use only supported OPs.`;
const ANSWER_MESSAGE = (question, answer) => `${question} = ${answer}`;

const COMMAND_EXIT = 'q';
const COMMAND_HELP = 'h';

async function main() {
    console.log(WELCOME_MESSAGE);

    const rl = Readline.createInterface({ input: stdin, output: stdout });

    while (true) {
        const command = await rl.question(ASK_FOR_COMMAND_MESSAGE);

        if (command == COMMAND_EXIT) {
            console.log(EXITING_MESSAGE);
            break;
        }

        if (command == COMMAND_HELP) {
            console.log(HELP_MESSAGE);
            continue;
        }

        const trimmedCommand = command.trim();
        const normalized = trimmedCommand.replace(/\s+/g, ' ');
        const entries = normalized.split(' ');

        if (entries.length != 3) {
            console.log(INCORRECT_COMMAND_MESSAGE);
            rl.write(normalized);
            continue;
        }

        const a = parseFloat(entries[0]);
        const b = parseFloat(entries[2]);
        const op = entries[1];
        let answer = 0;

        switch (op) {
            case '+': {
                answer = a + b;
                break;
            }
            case '-': {
                answer = a - b;
                break;
            }
            case '*': {
                answer = a * b;
                break;
            }
            case '/': {
                if (b == 0) {
                    console.log(DIVISION_BY_ZERO_MESSAGE);
                    continue;
                }

                answer = a / b;
                break;
            }
            case '//': {
                if (b == 0) {
                    console.log(DIVISION_BY_ZERO_MESSAGE);
                    continue;
                }

                answer = Math.floor(a / b);
                break;
            }
            case '%': {
                if (b == 0) {
                    console.log(DIVISION_BY_ZERO_MESSAGE);
                    continue;
                }

                answer = a % b;
                break;
            }
            case '**': {
                answer = Math.pow(a, b);
                break;
            }
            default: {
                console.log(UNKNOWN_COMMAND_MESSAGE(op));
                rl.write(normalized);
                continue;
            }
        }

        if (Math.abs(answer) > Number.MAX_VALUE || Math.abs(answer) < Number.MIN_VALUE) {
            console.log(CALCULATION_ERROR);
            continue;
        }

        console.log(ANSWER_MESSAGE(normalized, answer));
    }

    rl.close();
}

main();
