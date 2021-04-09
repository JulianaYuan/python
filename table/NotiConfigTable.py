#!/usr/bin/env python
# coding: utf-8

import pandas as pd

########################################################################

START_PORT = '/* list start */'
END_PORT = '/* list end */'

IN_FILE = './Notification.xlsx' # path+filename
TARGET_FILE = './WarnController.h'

TING_TAB = False
TING_NO_TAB = True

SET_LAST_N_COLUMNS_AS_INT = 2

START_FROM_INDEX = 1

########################################################################

def filter_data(in_file):
    try:
        ori_df = pd.read_excel(in_file)
        refer_df = pd.read_excel(in_file, sheet_name=1)
        filtered_df = refer_df.join(ori_df.set_index(ori_df.columns[0]), on=refer_df.columns[0], how='inner')
        return filtered_df
    except:
        print('Please check the input file!')
        return None
    
def df_to_text_abao_aligned(df, enable_newline=True):
    max_lens = df.applymap(lambda x: len(str(x))).max(axis=0).values.tolist()
    max_lens = [len(str(len(df.index)))] + max_lens
    #print(max_lens)
    if enable_newline:
        new_line_col = []
        tmp_sum_length = 10
        for i, length in enumerate(max_lens):
            tmp_sum_length += length
            if tmp_sum_length >= 100:
                new_line_col.append(i)
                tmp_sum_length = 10
    
    texts = []
    
    for i, row in df.iterrows():
        s = f'\t/*{i:*^{max_lens[0]}}*/'
        #s += '{ ' + '{}, "'.format(row[0])
        s += '{ ' + f'{row[0]:>{max_lens[1]}}, '
        #s += '", "'.join(map(str, row.values[1:]))
        for j, ch in enumerate(row.values[1:]):
            if isinstance(ch, str):
                tmp = '"' + ch + '", '
                s += tmp.ljust(max_lens[2+j]+4)
            else:
                s += f'{ch:>{max_lens[2+j]}}, '
            if enable_newline and (j+2) in new_line_col:
                s += '\n\t' + ' ' * (2 + max_lens[0] + 2 + 1)
        s = s[:-2] + '},\n\n'
        texts.append(s)
    return texts

def df_to_text_guagua_clear(df):
    texts = []
    
    for i, row in df.iterrows():
        s = f'\t/*{i:*^5}*/'
        #s += '{ ' + '{}, "'.format(row[0])
        s += '{ ' + f'{row[0]:>3}, '
        #s += '", "'.join(map(str, row.values[1:]))
        for j, ch in enumerate(row.values[1:]):
            if isinstance(ch, str):
                s += '"' + ch + '", ' + '\t'
            else:
                s += f'{ch:>3}, '+ '\t'
        s = s.rstrip()[:-1] + '},\n\n'
        texts.append(s)
    return texts

    

def output_to_cpp_file(target_file, df, out_file=None):
    print('Start to write the cpp/h file...')
    try:
        with open(target_file, 'r',encoding='utf-8') as f:
            content = f.readlines()
    except:
        print('Please check the target file!')
        return None
    
    ix_start, ix_end = 0, 0
    for lineno, line in enumerate(content):
        if not ix_start and line.strip() == START_PORT:
            ix_start = lineno
        if ix_start and line.strip() == END_PORT:
            ix_end = lineno
            break
    if TING_TAB:
        output = content[:ix_start+1] + df_to_text_abao_aligned(df) + content[ix_end:]
    elif TING_NO_TAB:
        output = content[:ix_start+1] + df_to_text_guagua_clear(df) + content[ix_end:]
    
    if not out_file:
        out_file = './WarnController.' + target_file.split('.')[-1]
    with open(out_file, 'w', encoding='utf-8') as f:
        for line in output:
            f.write(line)
        
    print('Done!\nThe output file is: {}'.format(out_file))
    
    return None

def main():
    df = filter_data(IN_FILE)
    last_n_cols = df.columns[-SET_LAST_N_COLUMNS_AS_INT:]
    df[last_n_cols] = df[last_n_cols].astype(int)
    df.index += START_FROM_INDEX
    if df is not None:
        output_to_cpp_file(TARGET_FILE, df)
    else:
        print('Quit!')


if __name__ == '__main__':
    main()
