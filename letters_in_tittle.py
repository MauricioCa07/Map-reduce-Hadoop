from mrjob.job import MRJob
from mrjob.step import MRStep
import csv 
from io import StringIO

class NameWordCounter(MRJob):

    def mapper(self, key, line):
        reader = csv.reader(StringIO(line))
        row = next(reader)
        
        title_field = row[0]
        for letter in title_field: 
            if letter != " ":
                yield letter, 1

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


