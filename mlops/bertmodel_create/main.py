from fastapi import FastAPI, UploadFile, File
from io import BytesIO
from PIL import Image
from predict import predict

app = FastAPI() # 인스턴스 생성

@app.get("/") # get method로 '/'에 해당하는  생성
def index():
    return {'Hello':'World!'}

@app.get("/api/v1/users/{user_name}")
def get_user(user_name):
    return {"user_name": user_name}

@app.post("/api/v1/predict")
async def image_predict(file: UploadFile = File(...)): # input: Image
    raw_data = await file.read()
    image_bytes_io = BytesIO(raw_data)
    img = Image.open(image_bytes_io)
    pred = predict(img)

    return pred # output: prediction
