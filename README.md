<a href="https://scan.coverity.com/projects/intel-academic-neurovectorizer">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/20079/badge.svg"/>
</a>

## NeuroVectorizer
Neurovectorizer is a framework that uses deep reinforcement learning (RL) to predict optimal vectorization compiler pragmas for `for loops` in C and C++ codes. The framework currently integrates with the LLVM compiler and can inject vectorization and interleaving factors. It is possible to support unrolling factors too by adding it as an action in the RL environment. More details are available in the paper. This paper appeared in CGO2020 and Passed all the artifact evaluations for reproducability.

Dependencies:
- TF2 (`pip install tensorflow`).
- Ray (`pip install ray`).
- RLlib (`pip install ray[rllib]`).
- LLVM (you need to have `/usr/lib/llvm-X.Y/lib/libclang.so.1` or equivalent working).
- clang (`pip install clang`).

The framework takes the text code of loops (detects them in the code) and uses an embedding generator. The output of this generator is fed to a neural network agent that predicts the optimal factors.

There are two modes of operation of this framework:
1) If you decide to use a neural network as a code embedding generator, it might be better to train end-to-end (the gradients of the NN of the RL agents back propogate to the input of the embedding generator). In that case you just have to run `python autovec.py` and if necessary modify "autovec.py" or "envs/neurvec.py" (mainly to change hyperparameters). Currently we implemented a neural network model based on code2vec. To use code2vec, you have first to run:
```
- cd preprocess
- source ./configure.sh //you need here to modify CODE2VEC_LOC and SOURCE_DIR to point to your files.
- source ./preprocess.sh //this will generate the bag of words of the training set for code2vec (the training set is in "training_data" feel free to add more samples).
- python autovec.py
```
Note that this will take a long time to finish training.

If you want to use another neural network in the embedding generator, you need to modify `get_obs` function in "envs/neurovec.py" and use that model in `autovec.py` (follow the TODOs in the code).

2) If you do not need to do end-to-end training (for example a pretrained code embedding generator, or use your own embedding generator that is not necessarily neural networks, then you need to modify this line https://github.com/AmeerHajAli/NeuroVectorizer/blob/e5e162761e6b51889b085fec2999f4780c0f91ec/envs/neurovec.py#L52 if you are using a pickle file of all the embeddings or `get_obs` function in "envs/neurovec.py" to return your embedding if you want it to query the generator in each step.  

# to run rollout/inference on files in the provided dataset\*:
`python temp_rollout.py <~/ray_results/NeuroVectorizer/PPO_NeuroVectorizerEnv_*/checkpoint_*/checkpoint-*> --rollout_dir <./rollout_data>`

\* if it is not in the dataset then use this comment line:`https://github.com/ucb-bar/NeuroVectorizer/blob/94fc4e88ecf63dcae0f7860b969348ea29b8ae64/envs/neurovec.py#L126` instead of the line after.

Note that this command will raise `ray.exceptions.RayActorError: The actor died unexpectedly before finishing this task`. This error is due to killing the ray worker after inferencing all the files. Ignore this error.


Please reach out to Ameer Haj Ali for any questions.


To cite this work:
```
@inproceedings{ameerhajalicgo,
 author = {Haj-Ali, Ameer and Ahmed, Nesreen and Willke, Ted and Shao, Sophia and Asanovic, Krste and Stoica, Ion},
 title = {NeuroVectorizer: End-to-End Vectorization with Deep Reinforcement Learning},
 booktitle = {Proceedings of the 2020 International Symposium on Code Generation and Optimization},
 series = {CGO 2020},
 year = {2020},
 location = {San Diego, USA},
 publisher = {ACM},
} 
```
