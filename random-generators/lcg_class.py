class Random():
    def __init__(self, seed = 1):
        self.__next = seed
        
    def get_number(self):
        self.__next = (1103515245 * self.__next + 12345) & 0xFFFFFFFF # Use only 32-bit
        return ((self.__next // 65536) % 32768) / 32768
    
    def set_seed(self, seed):
        self.__next = seed
