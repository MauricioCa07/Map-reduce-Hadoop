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
            yield director_field, 1
                            
    def combiner(self, key, values):
        yield key, sum(values)

    def reducer(self, key, values):
        yield None,(sum(values),key)

    def reducer_sorted(self, key, values):
        for key,value in sorted(values):
            yield key,value

    def steps(self):
        return [
            MRStep(

                mapper=self.mapper,
                combiner=self.combiner,
                reducer=self.reducer
            ),
            MRStep(
                reducer=self.reducer_sorted
            )
        ]

if __name__ == '__main__':
    NameWordCounter.run()



















