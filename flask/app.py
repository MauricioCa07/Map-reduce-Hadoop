
from flask import Flask, render_template

app = Flask(__name__)

def leer_datos(ruta_archivo: str):
    valores = []
    etiquetas = []
    with open(ruta_archivo, "r", encoding="utf-8") as f:
        for linea in f:
            partes = linea.split("\t")
            valor = float(partes[0])
            texto = partes[1].strip()

            if texto.startswith('"') and texto.endswith('"'):
                texto = texto[1:-1]

            valores.insert(0,valor)
            etiquetas.insert(0,texto)

    return valores, etiquetas

@app.route("/<metodo>/<descripion>")
def director_vs_rating(metodo,descripcion):
    ruta = "../"+metodo+".txt"
    valores, etiquetas = leer_datos(ruta)

    datos = list(zip(etiquetas, valores))
    return render_template("index.html", datos=datos,titulo=descripcion)


@app.route("/")
def main():
    return render_template("base.html")

if __name__ == "__main__":
    app.run(debug=True)
