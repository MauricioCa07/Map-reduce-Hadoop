from mrjob.job import MRJob
from mrjob.step import MRStep
import csv
from io import StringIO

class NameWordCounter(MRJob):
    
    def mapper(self, key, line):
        reader = csv.reader(StringIO(line))
        row = next(reader)
        
        if len(row) > 3:
            cast_field = row[3]  
            
            if cast_field:
                if cast_field.strip().startswith('[') and cast_field.strip().endswith(']'):
                    import ast
                    cast_members = ast.literal_eval(cast_field)
                else:
                    cast_members = [name.strip() for name in cast_field.split(',')]
                

                for actor in cast_members:
                    if isinstance(actor, str):
                        actor = actor.strip().replace('"', '').replace("'", "")
                        if actor:
                            yield actor, 1
                            
    
    def combiner(self, actor, counts):
        yield actor, sum(counts)
    
    def reducer(self, actor, counts):
        total_count = sum(counts)
        yield None, (total_count, actor)
    
    def reducer_sort(self, key, count_actor_pairs):
        sorted_pairs = sorted(count_actor_pairs)
        for count, actor in sorted_pairs:
            yield count, actor
    
    def steps(self):
        return [
            MRStep(
                mapper=self.mapper,
                combiner=self.combiner,
                reducer=self.reducer
            ),
            MRStep(
                reducer=self.reducer_sort
            )
        ]

if __name__ == '__main__':
    NameWordCounter.run()