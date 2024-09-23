from PIL.Image import Image
import tensorflow as tf
import numpy as np
from model_loader import model


def predict(image: Image): #pydantic -> type check
    # img => 규격화 (input image의 size normalisation)
    image = np.asarray(image.resize((224, 224)))[..., :3] # RGB 값만 받겠다
    print(f'Image first: {image}')
    image = np.expand_dims(image, 0)
    print(f'Image second: {image}')
    image = image/127.5 - 1.0 # (scaling)
    print(f'Image third: {image}')
    
    results = tf.keras.applications.imagenet_utils.decode_predictions(
        model.predict(image),
        3
    )[0]
    print(results)
    print(type(results))

    results_list = []
    for i in results:
        results_list.append({
            "Class": i[1],
            "Confidence": float(i[2]) # error with numpy.float32 
        })
    
    return results_list