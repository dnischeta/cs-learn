ASK_FOR_COMMAND_MESSAGE = 'Enter a command: '
INCORRECT_COMMAND_MESSAGE = 'Failed to parse last command. Please, enter correct command.'
COMMAND_EXIT = 'q'
COMMAND_HELP = 'h'

class CLI():
    def __init__(self, messages, processCommand):
        self.messages = messages
        self.processCommand = processCommand

    def run(self):
        while True:
            command = input(ASK_FOR_COMMAND_MESSAGE)

            if command == COMMAND_EXIT:
                print(self.messages['exit'])
                break

            if command == COMMAND_HELP:
                print(self.messages['help'])
                continue

            r = self.processCommand(command)
            
            if r:
                print(r)
