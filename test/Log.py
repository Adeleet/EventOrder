import time
from datetime import datetime
from random import choice, randint

from pandas import DataFrame


class Log:
    def __init__(self, cases, events, rows):
        self.cases = [i for i in range(cases)]
        self.events = [i for i in range(events)]
        self.case_data = [choice(self.cases) for i in range(rows)]
        self.event_data = [choice(self.events) for i in range(rows)]
        self.timestamp_data = [self.__rand_datetime__() for i in range(rows)]
        self.df = DataFrame({"Case": self.case_data,
                             "Event": self.event_data,
                             "Timestamp": self.timestamp_data})
        self.df = self.df.sort_values(by="Case")

    def __rand_datetime__(self):
        rand_time = randint(round(time.time() - len(self.events) * 50 * len(self.cases)),
                            round(time.time() + len(self.events) * 50 * len(self.cases)))
        return datetime.fromtimestamp(rand_time)

    def as_dataframe(self):
        return self.df

    def to_csv(self, path):
        self.df.to_csv(path, index=False)


log = Log(200, 50, 5000)
log.to_csv("c200-e50-r5000.csv")
