import csv
from mrjob.job import MRJob
from mrjob.step import MRStep

class NameWordCounter(MRJob):

    def mapper_init(self):
        self.header = None

    def mapper(self, _, line):
        row = next(csv.reader([line]))

        if self.header is None:
            self.header = row
        else:
            row_dict = dict(zip(self.header, row))
            name_field = row_dict.get("Director")
            if name_field:
                 yield name_field, 1

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
                mapper_init=self.mapper_init,
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
