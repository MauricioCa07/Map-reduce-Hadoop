# Movie Dataset Analysis with Hadoop MapReduce

In this project, we implemented a **batch data processing workflow** using **Hadoop MapReduce** to analyze a dataset called [**The Movies Dataset**](https://www.kaggle.com/datasets/rounakbanik/the-movies-dataset/data).

The goal was to demonstrate a complete **distributed data processing pipeline**, including:

- Data ingestion  
- Storage in HDFS  
- Parallel processing with MapReduce  
- Generation of meaningful and visual results  

---

## 🔍 What Did We Analyze?

We implemented **4 MapReduce jobs** using the [`MRJob`](https://mrjob.readthedocs.io/en/latest/) library. Here's what each job does:

1. **🎬 Number of Movies Directed by Each Director**  
   **File:** `repeated_directors.py`  
   ➤ Counts how many movies were directed by each director.

2. **⭐ Average Rating of Each Director**  
   **File:** `directors_rating.py`  
   ➤ Calculates the average rating of all movies directed by each director.

3. **🎭 Number of Movies Each Actor Appeared In**  
   **File:** `repeated_actors.py`  
   ➤ Counts how many movies each actor has participated in.

4. **🔤 Letter Frequency in Movie Titles**  
   **File:** `letters_in_title.py`  
   ➤ Computes the frequency of each letter (excluding spaces) in all movie titles.

---

## Want to Test Our Repository?

### Run Locally

1. Clone this repository:
   ```bash
    git clone <your-repo-url>
    cd <your-repo-folder>
    ```
2. download the [**The Movies Dataset**](https://www.kaggle.com/datasets/rounakbanik/the-movies-dataset/data)

3. Run the following commands:

    ```python
    python repeated_directors.py  ./Movie_Data_File.csv >> repeated_directors.txt

    python repeated_actors.py  ./Movie_Data_File.csv >> repeated_actors.txt

    python letters_in_tittle.py  ./Movie_Data_File.csv >> letters_in_tittle.txt

    python directors_rating.py  ./Movie_Data_File.csv >> directors_rating.txt

    cd flask && flask run
    ```
4. Open http://127.0.0.1/ in your browser to see a simple interface showing the results.


### Run on an AWS EMR Cluster



1. First, create an EMR cluster: 
    [** How to create an EMR cluster **](https://docs.aws.amazon.com/emr/latest/ManagementGuide/emr-gs.html)

2. From your local machine, run:

```bash
    chmod u+x init_script.bash

    ./init_script.bash <here_path_to_your_key> <public_DNS_of_your_cluster>
```
3. In the EMR cluster run: 

```python
    pip install mrjob

    hdfs dfs -put Movie_Data_File.csv /

    python directors_rating.py -r hadoop hdfs:///Movie_Data_File.csv >> directors_rating.txt
    python letters_in_tittle.py -r hadoop hdfs:///Movie_Data_File.csv >> letters_in_tittle.txt
    python repeated_actors.py -r hadoop hdfs:///Movie_Data_File.csv >> repeated_actors.txta
    python repeated_directors.py -r hadoop hdfs:///Movie_Data_File.csv >> repeated_directors.txt
```
4. Download the output files to your local machine using scp, sftp, or any method you prefer

5. Finally, run the Flask app:
```
    cd flask && flask run
```
6. Open http://127.0.0.1/ to view the interactive results.


## Technologies Used

    Python 3.11

    MRJob (MapReduce framework in Python)
    
    Apache Hadoop (EMR)

    Flask (for visualization)

    HDFS (Hadoop Distributed File System)