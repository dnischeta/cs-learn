name = input('Whom should I sign this to:')
file = input('Where shall I save it:')

with open(file, 'w', encoding='utf-8') as f:
    f.write(f'Hi {name}, we hope you enjoy learning Python with us! Best, Mooc.fi Team')