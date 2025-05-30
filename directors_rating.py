from mrjob.job import MRJob
from mrjob.step import MRStep
import csv 
from io import StringIO

class NameWordCounter(MRJob):

    def mapper(self, key, line):
        reader = csv.reader(StringIO(line))
        row = next(reader)
        
        if len(row) > 3:
            director_field = row[2]
            total_ratings = row[4]
            if total_ratings != "Average_rating" and total_ratings != "nan":
                yield director_field,(float(total_ratings),1)
            else: 
               yield "null",(0,0)               

    def reducer(self, key, values):
        total_sum = 0
        total_count = 0
        for val in values:
            total_sum += val[0]
            total_count += val[1]
        if total_count > 0:
            yield None, (total_sum / total_count,key)

    def reducer_sorted(self, key, values):
        for key,value in sorted(values):
            yield round(key,4),value

    def steps(self):
        return [
            MRStep(
                mapper=self.mapper,
                reducer=self.reducer
            ),
            MRStep(
                reducer=self.reducer_sorted
            )
        ]

if __name__ == '__main__':
    NameWordCounter.run()



