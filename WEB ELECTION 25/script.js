let escaños = 0;
let provinciaActual = '';

function seleccionarProvincia(provincia, escanos) {
    provinciaActual = provincia;
    escaños = escanos;

    document.getElementById('provinciaSeleccionada').textContent = provincia;
    document.getElementById('formularioVotos').classList.remove('hidden');
    document.getElementById('resultados').classList.add('hidden');
    document.getElementById('graficoEscanos').classList.add('hidden');
}

function calcularResultados() {
    const votosA = parseInt(document.getElementById('partidoA').value) || 0;
    const votosB = parseInt(document.getElementById('partidoB').value) || 0;
    const votosC = parseInt(document.getElementById('partidoC').value) || 0;

    const totalVotos = votosA + votosB + votosC;

    const resultados = [
        { partido: 'Partido A', votos: votosA, porcentaje: (votosA / totalVotos * 100).toFixed(2) },
        { partido: 'Partido B', votos: votosB, porcentaje: (votosB / totalVotos * 100).toFixed(2) },
        { partido: 'Partido C', votos: votosC, porcentaje: (votosC / totalVotos * 100).toFixed(2) }
    ];

    const repartoEscaños = sistemaDhondt([votosA, votosB, votosC], escaños);

    mostrarResultados(resultados, repartoEscaños);
    mostrarGraficoEscanos(repartoEscaños);
}

function sistemaDhondt(votos, escanos) {
    let divisores = votos.map(v => [v / 1, v / 2, v / 3, v / 4, v / 5, v / 6, v / 7, v / 8, v / 9, v / 10, v / 11, v / 12, v / 13, v / 14, v / 15, v / 16, v / 17, v / 18, v / 19, v / 20, v / 21, v / 22, v / 23, v / 24, v / 25, v / 26, v / 27, v / 28, v / 29, v / 30, v / 31, v / 32, v / 33, v / 34, v / 35].slice(0, escanos));
    let todosDivisores = [].concat(...divisores);
    todosDivisores.sort((a, b) => b - a);

    let escanosAsignados = [0, 0, 0];
    for (let i = 0; i < escanos; i++) {
        let maxIndex = divisores.findIndex(arr => arr.includes(todosDivisores[i]));
        escanosAsignados[maxIndex]++;
    }

    return escanosAsignados;
}

function mostrarResultados(resultados, repartoEscanos) {
    const tablaResultados = document.querySelector('#tablaResultados tbody');
    tablaResultados.innerHTML = ''; // Limpiar tabla previa

    resultados.forEach((resultado, index) => {
        let row = `<tr>
            <td>${resultado.partido}</td>
            <td>${resultado.votos}</td>
            <td>${resultado.porcentaje}%</td>
            <td>${repartoEscanos[index]}</td>
        </tr>`;
        tablaResultados.innerHTML += row;
    });

    document.getElementById('provinciaResultado').textContent = provinciaActual;
    document.getElementById('resultados').classList.remove('hidden');
}

// Función para mostrar el gráfico de escaños
function mostrarGraficoEscanos(repartoEscanos) {
    const data = [
        { name: 'Partido A', y: repartoEscanos[0], color: '#FF0000' },
        { name: 'Partido B', y: repartoEscanos[1], color: '#0000FF' },
        { name: 'Partido C', y: repartoEscanos[2], color: '#00FF00' }
    ];

    Highcharts.chart('graficoEscanos', {
        chart: {
            type: 'pie',
            height: '75%',
            plotBackgroundColor: null,
            plotBorderWidth: null,
            plotShadow: false
        },
        title: {
            text: 'Distribución de Escaños'
        },
        plotOptions: {
            pie: {
                innerSize: '50%',
                depth: 45,
                dataLabels: {
                    enabled: true,
                    format: '{point.name}: {point.y} escaños'
                }
            }
        },
        series: [{
            name: 'Escaños',
            data: data
        }]
    });

    document.getElementById('graficoEscanos').classList.remove('hidden');
}
