graph
[
  node
  [
    id MAT0025 CÁLCULO1 6
  ]
  node
  [
    id CIC0003 INTRODSISTEMASCOMPUTACIONAIS 4
  ]
  node
  [
    id CIC0004 ALGORITMOSPROGRCOMPUTADORES 6
  ]
  node
  [
	  id CIC0142 INFORMATICAESOCIEDADE 2
  ]

  node
  [
    id CIC0002 FUNDAMENTOSTEÓRDACOMPUTAÇÃO 4
  ]
  node
  [
	  id CIC0229 CIRCUITOSLÓGICOS 4
  ]
  node
  [
	  id CIC0090 ESTRUTURASDEDADOS 4
  ]
  node
  [
	  id CIC0231 LABORATÓRIOCIRCUITOSLÓGICOS 2
  ]
  node
  [
	  id MAT0026 CÁLCULO2 6
  ]
  node
  [
	  id MAT0031 INTRODUCAOAALGEBRALINEAR 4
  ]
  
  node
  [
	  id CIC0098 ORGARQDECOMPUTADORES 4
  ]
  node
  [
	  id CIC0197 TECNICASDEPROGRAMAÇÃO1 4
  ]
  node
  [
	  id MAT0034 ALGEBRA1 4
  ]
  node
  [
	  id MAT0053 CALCULONUMERICO 4
  ]
  node
  [
	  id EST0023 PROBABILIDADEEESTATÍSTICA 4
  ]
  
  node
  [
	  id CIC0182 LÓGICACOMPUTACIONAL1 4
  ]
  node
  [
	  id CIC0198 TECNICASDEPROGRAMAÇÃO2 4
  ]
  node
  [
	  id CIC0199 TEORIAEAPLICAÇÃODEGRAFOS 4
  ]
  node
  [
	  id CIC0124 REDESDECOMPUTADORES 4
  ]
  
  node
  [
	  id CIC0093 LINGUAGENSDEPROGRAMACAO 4
  ]
  node
  [
	  id CIC0202 PROGRAMAÇÃOCONCORRENTE 4
  ]

  node
  [
	  id CIC0105 ENGENHARIADESOFTWARE 4
  ]

  node
  [
	  id CIC0097 BANCOSDEDADOS 4
  ]

  node
  [
	  id CIC0135 INTROINTELIGENCIAARTIFICIAL 4
  ]

  node
  [
	  id CIC0104 SOFTWAREBASICO 4
  ]
  node
  [
	  id CIC0205 FUNDAMENTOSSISTOPERACIONAIS 4
  ]
  node
  [
	  id CIC0161 AUTÔMATOSECOMPUTABILIDADE 6
  ]
  node
  [
	  id CIC0101 SISTEMASDEINFORMACAO 4
  ]
  node
  [
	  id CIC0203 COMPUTAÇÃOEXPERIMENTAL 4
  ]

  node
  [
	  id CIC0189 PROJETOANÁLISEDEALGORITMOS 4
  ]
  node
  [
	  id CIC0204 COMPILADORES 4
  ]
  node
  [
	  id CIC0201 SEGURANÇACOMPUTACIONAL 4
  ]
  
  edge
  [
    comment "APC=>CL"
    source CIC0004
    target CIC0229
  ]
  edge
  [
    comment "APC=>LCL"
    source CIC0004
    target CIC0231
  ]
  edge
  [
    comment "APC=>ED"
    source CIC0004
    target CIC0090
  ]
  edge
  [
    comment "C1=>C2"
    source MAT0025
    target MAT0026
  ]
  edge
  [
    comment "C1=>PE"
    source MAT0025
    target EST0023
  ]
  edge
  [
    comment "ED=>TP1"
    source CIC0090
    target CIC0197
  ]
  edge
  [
    comment "C2=>CN"
    source MAT0026
    target MAT0053
  ]
  edge
  [
    comment "ED=>LC1"
    source CIC0090
    target CIC0182
  ]
  edge
  [
    comment "ED=>TAG"
    source CIC0090
    target CIC0199
  ]
  edge
  [
    comment "ED=>REDES"
    source CIC0090
    target CIC0124
  ]
  edge
  [
    comment "ED=>LP"
    source CIC0090
    target CIC0093
  ]
  edge
  [
    comment "ED=>SI"
    source CIC0090
    target CIC0101
  ]
  edge
  [
    comment "ED=>BD"
    source CIC0090
    target CIC0097
  ]
  edge
  [
    comment "ED=>IIA"
    source CIC0090
    target CIC0135
  ]
  edge
  [
    comment "TP1=>TP2"
    source CIC0197
    target CIC0198
  ]
  edge
  [
    comment "TP1=>ENG_SOFT"
    source CIC0197
    target CIC0105
  ]
  edge
  [
    comment "TP2=>PC"
    source CIC0198
    target CIC0202
  ]
  edge
  [
    comment "OAC=>PC"
    source CIC0098
    target CIC0202
  ]
  edge
  [
    comment "OAC=>SB"
    source CIC0098
    target CIC0104
  ]
  edge
  [
    comment "ED=>SB"
    source CIC0090
    target CIC0104
  ]
  edge
  [
    comment "PC=>FSO"
    source CIC0202
    target CIC0205
  ]
  edge
  [
    comment "A1=>AUTOMATOS"
    source MAT0034
    target CIC0161
  ]
  edge
  [
    comment "PE=>COMP_EXP"
    source EST0023
    target CIC0203
  ]
  edge
  [
    comment "ED=>COMP_EXP"
    source CIC0090
    target CIC0203
  ]
  edge
  [
    comment "ED=>PROJ_ANALI_ALGORIT"
    source CIC0090
    target CIC0189
  ]

  edge
  [
    comment "LP=>COMPILADORES"
    source CIC0093
    target CIC0204
  ]
  edge
  [
    comment "SB=>COMPILADORES"
    source CIC0104
    target CIC0204
  ]
  edge
  [
    comment "AUTOMATOS=>COMPILADORES"
    source CIC0161
    target CIC0204
  ]
  edge
  [
    comment "REDES=>SEGURANCA"
    source CIC0124
    target CIC0201
  ]
]