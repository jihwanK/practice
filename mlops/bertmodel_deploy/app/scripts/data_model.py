from pydantic import BaseModel

def BertInput():
    text: list[str]

def BertOuput():
    model_name: str
    text: list[str]
    labels: list[str]
    scores: list[float]
    prediction_time: float
