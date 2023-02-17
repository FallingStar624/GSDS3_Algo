#!/bin/bash

#SBATCH --job-name=notebook  # 작업창에 뜨는 이름
#SBATCH --nodes=1            # 몇개 노드 받을건지
#SBATCH --gres=gpu:0         # gpu 1개
#SBATCH --time=0-12:00:00    # 12 hours timelimit
#SBATCH --mem=32000MB        # RAM

source /home/${USER}/.bashrc
conda activate main

srun jupyter nbconvert --execute --to notebook --inplace /home/sungwoopark/twoday/pokemon/pokemon.ipynb 
